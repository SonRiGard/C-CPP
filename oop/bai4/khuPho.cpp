#include "khuPho.h"
#include "input.h"

khuPho::khuPho(){
    std::cout << "Nhap so luong Ho gia dinh cua khu pho : ";
    int tmp = 0;
    std::cin >> tmp;
    std::cin.ignore();
    std::cout << "----------------------------------------\n";
    for(int i = 0 ; i<tmp;i++){
        ThemHoGiaDinh();
    }
};

khuPho::~khuPho(){
    for (auto ptr:ptrHoGiaDinh){
        delete ptr;
    }
};

void khuPho::ThemHoGiaDinh (){

    hoGiaDinh* tmp = new hoGiaDinh;
    std::cout << "Nhap so nha cua ho gia dinh: ";
    int tmpSoNha = getUint16();
    tmp-> CaiSoNha (tmpSoNha);
    std::cout << "Nhap so luong thanh vien: ";
    int tmpSothanhVien = getUint16();
    for (int i=0; i<tmpSothanhVien; i++){
        std::cout << "----------------------------------------\n";
        std::cout << "Nhap thong tin Thanh vien thu " <<i+1<< " : \n";
        std::string tmpHovaten, tmpNgheNghiep, tmpCMND;
        int tmptuoi;
        
        std::cout << "Nhap ten: ";
        std::getline(std::cin,tmpHovaten);
        std::cout << "Nhap tuoi: ";
        tmptuoi = getUint8();
        std::cin.ignore();
        std::cout << "Nhap nghe nghiep: ";
        std::getline(std::cin,tmpNgheNghiep);
        do{
        std::cout << "Nhap CMND: ";
        std::getline(std::cin,tmpCMND);
        }while (KiemTraCMND(tmpCMND) || tmp->CheckCMNDNha(tmpCMND) );

        tmp->ThemThanhVien(new Nguoi(tmpHovaten,tmptuoi,tmpNgheNghiep,tmpCMND));
    }
    ptrHoGiaDinh.push_back(tmp);
};

void khuPho::HienThiThongTinKhuPho(){
    std::cout<<"-------------- Khu Pho ------------------\n";
    for(auto ptr:ptrHoGiaDinh){
        ptr->HienThoThongTinNha();
    }
};
//tra ve true neu da ton tai cmnd / false neu chua co
bool khuPho::KiemTraCMND(std::string cmnd){
    for (auto ptr:ptrHoGiaDinh){
        if(ptr->CheckCMNDNha(cmnd)){
            return true;
        }
    }
    return false;
    std::cout << "flase cmnd";
};