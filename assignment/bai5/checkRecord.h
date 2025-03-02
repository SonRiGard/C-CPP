#ifndef CHECKRECORD_H
#define CHECKRECORD_H

#include <iostream>
#include <vector>
#include <string>


struct HexRecord {
    std::string startCode;  
    int byteCount;
    int address;
    int recordType;
    std::string data;
    int checksum;
    bool isValid;
};

class CheckRecord {
public:
    static HexRecord parseRecord(const std::string &line);
    static bool validateRecord(const HexRecord &record);
    static void processHexFile(const std::vector<std::string> &lines);
};

#endif // CHECKRECORD_H
