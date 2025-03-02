#include "iofile.h"
#include "checkRecord.h"
using namespace std;
int main() {
    std::string inputFile = "hex1";
    std::string outputFile = "output";
    // Đọc file
    std::vector<std::string> lines = IOFile::readLines(inputFile);
    
    for (const auto &line : lines) {
        std::cout << line << std::endl;
    }
    // Xử lý kiểm tra và hiển thị nội dung file

    std::vector<std::string> outputLines;
    CheckRecord::processHexFile(lines);

    return 0;
}

