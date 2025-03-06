#include "khoa.hpp"
#include "controller.hpp"
#include "config.hpp"

khoa khoaCNTT;

//thao tac tim kiem, tim kiem type ,... voi moi sinh vien theo ma sinh vien

int main (){
    controller khoaController;

    khoaController.addController("SHOW","Hien thi danh sach sinh vien!",[](){
        khoaCNTT.hienThiSinhVien();
    });

    khoaController.addController("TYPE","Kiem tra loai sinh vien theo MSV!",[](){
        khoaCNTT.checkChinhQuySinhVienTheoMSV();
    });
    //diem theo ki
    khoaController.addController("DTK","Hien thi tat ca diem trung binh theo ky!",[](){
        khoaCNTT.hienThiDiemTrungBinhTheoKy();
    });

    //tong so sinh vien chinh quy
    khoaController.addController("TSCQ","Tong so sinh vien chinh quy!",[](){
        std::cout<<"Tong so sinh vien chinh quy: "<<khoaCNTT.tongSoSVChinhQuy()<<std::endl;
    });
    
    //tim sinh vien co diem dau vao cao nhat
    khoaController.addController("DVCN","Sinh vien co diem dau vao cao nhat!",[](){
        khoaCNTT.SVCodiemDauVaoCaoNhat();
    });
    
    //tim sinh vien tai noi lam dao tao
    khoaController.addController("TNDD","Sinh vien tai noi dao tao!",[](){
        std::string noiDaoTao;
        std::cout<<"Nhap noi dao tao: ";
        std::getline(std::cin,noiDaoTao);
        khoaCNTT.SvTaiNoiDaoTao(noiDaoTao);
    });

    //tim sinh vien co diem hoc ky lon hon 8
    khoaController.addController("DHK","Sinh vien co diem hoc ky lon hon 8!",[](){
        khoaCNTT.SVCodiemCuaHocKyLonHon();
    });

    //tim sinh vien co diem trung binh cao nhat
    khoaController.addController("DCN","Sinh vien co diem hoc ky cao nhat cua khoa!",[](){
        khoaCNTT.SinhVienCoDiemHocKyCaoNhatCuaKhoa();
    });
    
    //sap sep sinh vien tang dan theo loai va giam dan theo nam vao
    khoaController.addController("SORT","Sap xep sinh vien theo nam va nam vao hoc!",[](){
        khoaCNTT.sapSepSVTangDanTheoLoaiGiamDanTheoNamVao();
    });

    //Thong ke so luong sinh vien theo nam
    khoaController.addController("TKE","Thong ke so luong sinh vien theo nam!",[](){
        khoaCNTT.thongKeSoLuongSinhVienTheoNam();
    });

    #ifdef AUTO_INPUT_MODE
    //them sinh vien tu dong
    khoaController.addController("ADD","Them sinh vien moi!",[](){
        std::srand(std::time(0)); 
        for(int i = 0; i<NUMBER_OF_STUDENTS; i++)
        khoaCNTT.themSinhVienAuto();
    });
    #endif

    #ifdef MANUAL_INPUT_MODE
    khoaController.addController("ADD","Them sinh vien moi!",[](){
        khoaCNTT.themSinhVien();
    });
    #endif

    khoaController.run();
}