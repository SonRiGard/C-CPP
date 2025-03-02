#ifndef IOFILE_H
#define IOFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class IOFile {
public:
    // Đọc từng dòng của file và lưu vào vector
    static std::vector<std::string> readLines(const std::string &filename);

    // Ghi từng dòng vào file
    static bool writeLines(const std::string &filename, const std::vector<std::string> &lines);
};

#endif // IOFILE_H
