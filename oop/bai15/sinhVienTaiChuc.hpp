#pragma once
#include "sinhVien.hpp"

class sinhVienTaiChuc : public sinhVien {
    private:
        std::string noiDaoTao;
    
    public:
        sinhVienTaiChuc();
        sinhVienTaiChuc(std::string& maSV, std::string& hoTen, std::string& doB, uint16_t& namVaoHoc, float& diemDauVao, std::string& noiDaoTao);
        sinhVienTaiChuc(std::string&& maSV, std::string&& hoTen, std::string&& doB, uint16_t& namVaoHoc, float& diemDauVao, std::string&& noiDaoTao);
        sinhVienTaiChuc (const sinhVienTaiChuc&);
        ~sinhVienTaiChuc();

        std::string getNoiDaoTao();

        enumTypeSV loaiSinhVien();
        void hienThiSinVien () override;
        std::string layNoiDaoTao() override;
        

    };