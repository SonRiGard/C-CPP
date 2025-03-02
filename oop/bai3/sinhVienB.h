#ifndef SINHVIENB_H_
#define SINHVIENB_H_
#include <iostream>
#include <string>
#include "sinhVien.h"

#include <iomanip>

class sinhVienB:public sinhVien{
    private:
        std::string khoiThi = "Khoi C: Van,Su,Dia";
    public:
        sinhVienB(int SBD,std::string ten,std::string diaChi, int mucUuTien)
            :sinhVien(SBD,ten,diaChi,mucUuTien){};

        void printSinhVien(){
            std::cout <<std::right<<std::setw(5)<<std::setfill('0') << SBD << " :"<< ten <<" - "
                << diaChi<<" - "<<mucUuTien<<" - "<< khoiThi <<std::endl;
        };
};
#endif