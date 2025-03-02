#include "checkRecord.h"
#include <sstream>
#include <iomanip>

static int segmentBase = 0;
static int upperAddress = 0;
static int add_width = 4;

// Hàm chuyển đổi chuỗi HEX sang số nguyên
int hexStringToInt(const std::string &hexStr) {
    int value;
    std::stringstream ss;
    ss << std::hex << hexStr;
    ss >> value;
    return value;
}

HexRecord CheckRecord::parseRecord(const std::string &line) {
    HexRecord record;
    record.isValid = false;

    if (line.empty() || line[0] != ':') {
        std::cerr << "Error: Missing start code ':' at the beginning of record!" << std::endl;
        return record;
    }

    try {
        record.startCode = ":";
        record.byteCount = hexStringToInt(line.substr(1, 2));
        record.address = hexStringToInt(line.substr(3, 4));
        record.recordType = hexStringToInt(line.substr(7, 2));
        record.data = line.substr(9, record.byteCount * 2);
        record.checksum = hexStringToInt(line.substr(9 + record.byteCount * 2, 2));

        // Kiểm tra checksum
        int sum = record.byteCount + (record.address >> 8) + (record.address & 0xFF) + record.recordType;
        for (size_t i = 0; i < record.data.size(); i += 2) {
            sum += hexStringToInt(record.data.substr(i, 2));
        }
        sum = (sum + record.checksum) & 0xFF;
        if (sum != 0 || (record.data.size() / 2 != record.byteCount)) {
            std::cerr << "Error: Invalid checksum for record: " << line << std::endl;
            return record;
        }

        // **Xử lý Extended Segment Address Record (Type 02)**
        if (record.recordType == 0x02) {
            segmentBase = hexStringToInt(record.data) * 0x10; // Tính Segment Base Address
            upperAddress = 0; // Reset upper address (Type 04 không còn hiệu lực)
            add_width = 5;
            std::cout << "Updated Segment Base Address: 0x" << std::hex << segmentBase << std::endl;
        }

        // **Xử lý Extended Linear Address Record (Type 04)**
        if (record.recordType == 0x04) {
            upperAddress = hexStringToInt(record.data); // Cập nhật Upper Address
            add_width = 8;
            segmentBase = 0; // Reset segment base (Type 02 không còn hiệu lực)
            std::cout << "Updated Upper Address: 0x" << std::hex << upperAddress << std::endl;
        }

        // **Xử lý Data Record (Type 00)**
        if (record.recordType == 0x00) {
            int absoluteAddress;
            if (upperAddress) {
                absoluteAddress = (upperAddress << 16) + record.address; // Tính theo Upper Address (Type 04)
            } else {
                absoluteAddress = segmentBase + record.address; // Tính theo Segment Base (Type 02)
            }

            std::cout << "Absolute Memory Address: 0x" << std::setw(add_width) << std::setfill('0')<<std::hex << absoluteAddress
                      << " | Data: " << record.data << std::endl;
        }

        record.isValid = true;
    } catch (...) {
        std::cerr << "Error: Invalid record format!" << std::endl;
    }

    return record;
}

// Hàm kiểm tra record có hợp lệ không
bool CheckRecord::validateRecord(const HexRecord &record) {
    return record.isValid;
}

// Xử lý toàn bộ file HEX
void CheckRecord::processHexFile(const std::vector<std::string> &lines) {
    bool hasEOF = false;
    for (const auto &line : lines) {
        HexRecord record = parseRecord(line);
        if (!validateRecord(record)) {
            std::cerr << "The file has been corrupted due to an invalid record!" << std::endl;
            return;
        }

        // Nếu là End Of File record (Record Type = 01)
        if (record.recordType == 0x01) {
            hasEOF = true;
        }
    }

    if (!hasEOF) {
        std::cerr << "File error: 'End Of File record' does not exist!" << std::endl;
    } else {
        std::cout << "Valid HEX file!" << std::endl;
    }
}
