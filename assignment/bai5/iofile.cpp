#include "iofile.h"

// Hàm đọc file và lưu từng dòng vào vector
std::vector<std::string> IOFile::readLines(const std::string &filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Không thể mở file: " << filename << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Hàm ghi vector<string> vào file
bool IOFile::writeLines(const std::string &filename, const std::vector<std::string> &lines) {
    std::ofstream file(filename);
    
    if (!file) {
        std::cerr << "Không thể ghi vào file: " << filename << std::endl;
        return false;
    }

    for (const auto &line : lines) {
        file << line << std::endl;
    }
    
    return true;
}