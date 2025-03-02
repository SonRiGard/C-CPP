#ifndef SINHVIENA_H_
#define SINHVIENA_H_
#include <iostream>
#include <string>
#include "sinhVien.h"
#include <iomanip>

class sinhVienA:public sinhVien{
    private:
        std::string khoiThi = "Khoi A: Toan,Ly,Hoa";
    public:
        sinhVienA(int SBD,std::string ten,std::string diaChi, int mucUuTien)
            :sinhVien(SBD,ten,diaChi,mucUuTien){};

        void printSinhVien()override{
            std::cout <<std::right<<std::setw(5)<<std::setfill('0') << SBD << " :"<< ten <<" - "
            << diaChi<<" - "<<mucUuTien<<" - "<< khoiThi<<std::endl;
        };
    
};
#endif