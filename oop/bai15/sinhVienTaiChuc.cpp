#include "sinhVienTaiChuc.hpp"

sinhVienTaiChuc::sinhVienTaiChuc(){

};

sinhVienTaiChuc::sinhVienTaiChuc(const std::string& maSV,const std::string& hoTen,const std::string& doB,const uint16_t& namVaoHoc,const float& diemDauVao,const std::string& noiDaoTao)
{
    this->maSinhVien = maSV; 
    this->hoTen = hoTen;  
    this->doB = doB;
    this->namVaoHoc = namVaoHoc;
    this->diemDauVao = diemDauVao;
    this->noiDaoTao = noiDaoTao;
};


sinhVienTaiChuc::sinhVienTaiChuc(std::string&& maSV, std::string&& hoTen, std::string&& doB, uint16_t& namVaoHoc, float& diemDauVao, std::string&& noiDaoTao)
:sinhVien(std::move(maSV),std::move(hoTen),std::move(doB),namVaoHoc,diemDauVao),noiDaoTao(noiDaoTao)
{
};


sinhVienTaiChuc::sinhVienTaiChuc (const sinhVienTaiChuc& other):sinhVien(other),noiDaoTao(other.noiDaoTao)
{
};

sinhVienTaiChuc::~sinhVienTaiChuc(){
    for(auto ptr:bangDiem){
        delete ptr;
    }
};

std::string sinhVienTaiChuc::getNoiDaoTao() {
    return noiDaoTao;
};

enumTypeSV sinhVienTaiChuc::loaiSinhVien(){
    return type_taiChuc;
};

void sinhVienTaiChuc::hienThiSinVien (){
    std::cout << "----------------------------------------------\n";
    std::cout << "Ma sinh vien: " << maSinhVien << " | Ho ten: " << hoTen << " | Nam vao hoc: " << namVaoHoc << " | Diem dau vao: " << diemDauVao << std::endl;
    std::cout << "Bang diem: \n";
    xuatDiem();
};

std::string sinhVienTaiChuc::layNoiDaoTao(){
    return noiDaoTao;
}