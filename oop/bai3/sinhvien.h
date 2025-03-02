#ifndef SINHVIEN_H_
#define SINHVIEN_H_
#include <iostream>
#include <string.h>

class sinhVien{
    protected:
        unsigned int SBD;
        std::string ten;
        std::string diaChi;
        int mucUuTien;
    public:
        sinhVien(int SBD,std::string ten,std::string diaChi, int mucUuTien):SBD(SBD),ten(ten),diaChi(diaChi),mucUuTien(mucUuTien){};
        virtual void printSinhVien() = 0;
        unsigned int getSBD(){
            return this->SBD;
        };
};
#endif