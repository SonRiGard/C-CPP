#pragma once
#include "sinhVien.hpp"
#include <vector>
#include <iostream>
#include <string>
#include "sinhVienTaiChuc.hpp"
#include "sinhVienChinhQuy.hpp"
#include "config.hpp"

class khoa {
    private:
        std::vector<sinhVien*> danhSachSinhVien;

        int SoLuongSinhVienTheoNam(uint32_t year);
        uint32_t layNamVaoThapNhat();
        uint32_t layNamVaoCaoNhat();
    public:
        khoa();
        ~khoa();

        // Quản lý sinh viên
        void themSinhVien();
        void hienThiSinhVien();
        void checkChinhQuySinhVienTheoMSV();
        void hienThiDiemTrungBinhTheoKy();
        void SVCodiemDauVaoCaoNhat();
        uint32_t tongSoSVChinhQuy();
        void SvTaiNoiDaoTao(std::string noiDaoTao); 
        void SVCodiemCuaHocKyLonHon(int diem = 8);
        sinhVien* SinhVienCoDiemHocKyCaoNhatCuaKhoa();
        void sapSepSVTangDanTheoLoaiGiamDanTheoNamVao();
        void thongKeSoLuongSinhVienTheoNam();
        void themSinhVienAuto();
    };