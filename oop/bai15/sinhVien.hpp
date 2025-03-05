#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ketQuaHocTap.hpp"
#include <cstdint>

typedef enum enumTypeSV{
    type_taiChuc,
    type_chinhQuy
}enumTypeSV;

class sinhVien {
    protected:
        std::string maSinhVien;
        std::string hoTen;
        std::string doB; // ngay thang nam sinh
        uint16_t namVaoHoc;
        float diemDauVao;
        std::vector<ketQuaHocTap*> bangDiem;
    
    public:
        sinhVien();
        sinhVien(std::string&& maSV, std::string&& hoTen, std::string&& doB, uint16_t& namVaoHoc, float& diemDauVao);//move constructor
        sinhVien(const sinhVien&);//deep copy constructor
        sinhVien(std::string& maSV, std::string& hoTen, std::string& doB, uint16_t namVaoHoc, float diemDauVao);

        virtual ~sinhVien();
        virtual enumTypeSV loaiSinhVien () = 0;//pure function return type of student
        void nhapDiem();
        void xuatDiem();
        virtual void hienThiSinVien()=0;
        std::string layMaSinhVien();
        float layDiemTheoKy();
        float layDiemTheoKy(int kyHoc);
        float layDiemDauVao();
        float layDiemHocKyGanNhat();
        float layDiemHocKyCaoNhat();
        uint16_t layNamVaoHoc();
        virtual std::string layNoiDaoTao()=0;
        
    };
    