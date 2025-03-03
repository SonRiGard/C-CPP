#include "hoGiaDinh.h"
#include "input.h"

hoGiaDinh::hoGiaDinh(){

};

hoGiaDinh::~hoGiaDinh(){
    for (auto ptr:ptrThanhVien){
        delete ptr;
    }
}

void hoGiaDinh::CaiSoNha(int soNha){
    this->soNha = soNha;
}

void hoGiaDinh::ThemThanhVien (){
    std::cout << "Nhap thong tin Thanh vien\n";
    std::string tmpHovaten, tmpNgheNghiep, tmpCMND;
    int tuoi;
    std::cout << "Nhap ten: ";
    std::getline(std::cin,tmpHovaten);
    std::cout << "Nhap tuoi: ";
    tuoi = getUint8();
    std::cout << "Nhap nghe nghiep: ";
    std::getline(std::cin,tmpNgheNghiep);
    std::cout << "Nhap CMND: ";
    std::getline(std::cin,tmpCMND);

    ptrThanhVien.push_back(new Nguoi(std::move(tmpHovaten), tuoi, std::move(tmpNgheNghiep), std::move(tmpCMND)));
};

void hoGiaDinh::ThemThanhVien (Nguoi* ptrNguoi){
    ptrThanhVien.push_back(ptrNguoi);
}

int hoGiaDinh::GetSoLuongThanhVien(){
    return ptrThanhVien.size();
};

void hoGiaDinh::HienThoThongTinNha(){
    std::cout <<"============= Thong tin Nha ==============\n";
    for (auto ptr:ptrThanhVien){
        ptr->HienThiThongTinNguoi();
    }
};
//return true neu da ton tai so cmnd nay roi
bool hoGiaDinh::CheckCMNDNha(std::string cmnd){
    for (auto ptr:ptrThanhVien){
        if(cmnd == ptr->LaySoCMNN()){
            std::cout << "Da ton tai mot so cmnd nay\n";
            return true;
        }
    }
    
    return false;
}
