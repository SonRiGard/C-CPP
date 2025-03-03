#include "nguoi.h"
#include <string>

Nguoi::Nguoi(std::string& hoVaTen,int tuoi,std::string& ngheNghiep,std::string& cmnd)
:hoVaTen(hoVaTen),tuoi(tuoi),ngheNghiep(ngheNghiep),cmnd(cmnd){};

Nguoi::Nguoi(std::string&& hoVaTen,int tuoi,std::string&& ngheNghiep,std::string&& cmnd)
:hoVaTen(hoVaTen),tuoi(tuoi),ngheNghiep(ngheNghiep),cmnd(cmnd){};

Nguoi::~Nguoi(){

};

std::string Nguoi::LayhoVaTen(){
    return this->hoVaTen;
}

int Nguoi::LayTuoi(){
    return this->tuoi;
}
std::string Nguoi::LayNgheNghiep(){
    return this->ngheNghiep;
}

std::string Nguoi::LaySoCMNN(){
    return this->cmnd;
};

void Nguoi::HienThiThongTinNguoi(){
    std::cout<< "-------------------------------------\n";
    std::cout << hoVaTen <<": "<<tuoi<<"tuoi  - Nghe nghiep: "<< ngheNghiep<<" CMND: "<<cmnd<<std::endl;
}; 