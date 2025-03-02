#ifndef SINHVIENC_H_
#define SINHVIENC_H_
#include <iostream>
#include <string>
#include "sinhVien.h"
#include <iomanip>

class sinhVienC:public sinhVien{
    private:
        std::string khoiThi = "Khoi C: Toan,Ly,Hoa";
    public:
        sinhVienC(int SBD,std::string ten,std::string diaChi, int mucUuTien)
            :sinhVien(SBD,ten,diaChi,mucUuTien){};

        void printSinhVien(){
            std::cout <<std::right<<std::setw(5)<<std::setfill('0') << SBD << " :"<< ten <<" - "<< diaChi
            <<" - "<<mucUuTien<<" - "<< khoiThi<<std::endl;
        };
};
#endif