#include "sinhVienChinhQuy.hpp"

sinhVienChinhQuy::sinhVienChinhQuy(){

};

sinhVienChinhQuy::sinhVienChinhQuy(std::string&& maSV, std::string&& hoTen, std::string&& doB, uint16_t& namVaoHoc, float& diemDauVao)
:sinhVien(std::move(maSV),std::move(hoTen),std::move(doB),namVaoHoc,diemDauVao)
{
};

//only copy data member, not copy pointer to vector ketQuaHocTap
sinhVienChinhQuy::sinhVienChinhQuy(const sinhVienChinhQuy& other):sinhVien(other)
{
};

sinhVienChinhQuy::~sinhVienChinhQuy(){
};

enumTypeSV sinhVienChinhQuy::loaiSinhVien(){
    return type_chinhQuy;
};

void sinhVienChinhQuy::hienThiSinVien (){
    std::cout << "----------------------------------------------\n";
    std::cout << "Ma sinh vien: " << maSinhVien << " | Ho ten: " << hoTen << " | Nam vao hoc: " << namVaoHoc << " | Diem dau vao: " << diemDauVao << std::endl;
    std::cout << "Bang diem: \n";
    xuatDiem();
};

std::string sinhVienChinhQuy::layNoiDaoTao() {
    return "Chua co noi dao tao";
};

