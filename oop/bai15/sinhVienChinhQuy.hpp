#pragma once

#include "sinhVien.hpp"
class sinhVienChinhQuy : public sinhVien {
    public:
        sinhVienChinhQuy();
        sinhVienChinhQuy(std::string&& maSV, std::string&& hoTen, std::string&& doB, uint16_t& namVaoHoc, float& diemDauVao);//move constructor
        sinhVienChinhQuy(const sinhVienChinhQuy& other);//deep copy constructor
        ~sinhVienChinhQuy();
        
        enumTypeSV loaiSinhVien();
        void hienThiSinVien () override;
        std::string layNoiDaoTao() override;

    };