#pragma once
#include "sinhVien.hpp"

class sinhVienTaiChuc : public sinhVien {
    private:
        std::string noiDaoTao;
    
    public:
        sinhVienTaiChuc();
        sinhVienTaiChuc(const std::string& maSV,const std::string& hoTen,const std::string& doB,const uint16_t& namVaoHoc,const float& diemDauVao,const std::string& noiDaoTao);
        sinhVienTaiChuc(std::string&& maSV, std::string&& hoTen, std::string&& doB, uint16_t& namVaoHoc, float& diemDauVao, std::string&& noiDaoTao);
        sinhVienTaiChuc (const sinhVienTaiChuc&);
        ~sinhVienTaiChuc();

        std::string getNoiDaoTao();

        enumTypeSV loaiSinhVien();
        void hienThiSinVien () override;
        std::string layNoiDaoTao() override;
    };