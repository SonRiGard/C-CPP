#include "khoa.hpp"
#include "exception.hpp"


khoa::khoa(){

};

khoa::~khoa(){
    for(auto ptr:danhSachSinhVien){
        delete ptr;
    }
};

// Quản lý sinh viên
void khoa::themSinhVien(){
    bool invaledInfor = false;
    while(!invaledInfor){
        try{
            std::cout<<"Nhap ten sinh vien:";
            std::string hoTen;
            std::getline(std::cin,hoTen);
            InvalidFullNameException(hoTen);

            std::cout<<"Nhap ma sinh vien:";
            std::string maSV;
            std::getline(std::cin,maSV);

            std::cout<<"Nhap ngay sinh:";
            std::string doB;
            std::getline(std::cin,doB);
            InvalidDOBException(doB);

            std::cout<<"Nhap nam vao hoc:";
            uint16_t namVaoHoc;
            std::cin>>namVaoHoc;

            std::cout<<"Nhap diem dau vao:";
            float diemDauVao;
            std::cin>>diemDauVao;

            std::cout<<"Luu chon loai sinh Vien 0-Tai Chuc; 1-Chinh Quy:";
            int loaiSV;
            std::cin>>loaiSV;

            std::string noiDaoTao;
            switch ((enumTypeSV)loaiSV)
            {
            case type_taiChuc:
                std::cout<<"Nhap noi dao tao:";
                std::cin.ignore();
                std::getline(std::cin,noiDaoTao);
                danhSachSinhVien.push_back(new sinhVienTaiChuc(std::move(maSV),std::move(hoTen),std::move(doB),namVaoHoc,diemDauVao,std::move(noiDaoTao)));
                break;
                
            case type_chinhQuy:
                danhSachSinhVien.push_back(new sinhVienChinhQuy(std::move(maSV),std::move(hoTen),std::move(doB),namVaoHoc,diemDauVao));
                break;

            default:
                std::cout<<"Loai sinh vien khong hop le!\n";
                break;
            }
            invaledInfor = true;
        }
        catch(const std::exception& e){
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
};

void khoa::hienThiSinhVien(){
    for(auto ptr:danhSachSinhVien){
        ptr->hienThiSinVien();
    }
};

void khoa::hienThiDiemTrungBinhTheoKy(){
    std::cout<<"Nhap ky hoc:";
    int kyHoc;
    std::cin>>kyHoc;
    for(auto ptr:danhSachSinhVien){
        std::cout<<"Ma sinh vien: "<<ptr->layMaSinhVien()<<" - Diem trung binh ky "<<kyHoc<<": ";
        ptr->layDiemTheoKy(kyHoc);
    }
};

void khoa::checkChinhQuySinhVienTheoMSV(){
    std::cout<<"Nhap ma sinh vien:";
    std::string maSV;
    std::cin>>maSV;
    for(auto ptr:danhSachSinhVien){
        if(ptr->layMaSinhVien() == maSV){
            if(ptr->loaiSinhVien() == type_chinhQuy){
                std::cout<<"Sinh vien chinh quy!\n";
            }else{
                std::cout<<"Sinh vien tai chuc!\n";
            }
            return;
        }
    }
};

uint32_t khoa::tongSoSVChinhQuy(){
    uint32_t count = 0;
    for(auto ptr:danhSachSinhVien){
        if(ptr->loaiSinhVien() == type_chinhQuy){
            count++;
        }
    }
    return count;
};

void khoa::SVCodiemDauVaoCaoNhat(){
    float max = 0;
    sinhVien* sv = nullptr;
    for(auto ptr:danhSachSinhVien){
        if(ptr->layDiemDauVao() > max){
            max = ptr->layDiemDauVao();
            sv = ptr;
        }
    }
    std::cout<<"Sinh vien co diem dau vao cao nhat la: \n";
    sv->hienThiSinVien();
}

void khoa::SvTaiNoiDaoTao(std::string noiDaoTao){
    for(auto ptr:danhSachSinhVien){
        if(ptr->loaiSinhVien() == type_taiChuc){
            if(((sinhVienTaiChuc*)ptr)->layNoiDaoTao() == noiDaoTao){
                ptr->hienThiSinVien();
            }
        }
    }
};

void khoa::SVCodiemCuaHocKyLonHon(int diem){
    std::cout<<"Sinh vien co diem hoc ky lon hon "<<diem<<" la: \n";
    for(auto ptr:danhSachSinhVien){
        if(ptr->layDiemHocKyGanNhat() > diem){
            ptr->hienThiSinVien();
        }
    }
};

sinhVien* khoa::SinhVienCoDiemHocKyCaoNhatCuaKhoa(){
    std::cout << "Sinh vien co diem hoc ky cao nhat cua khoa la: \n";
    int max = 0;
    sinhVien* sv = nullptr;
    for(auto ptr:danhSachSinhVien){
        if(ptr->layDiemHocKyCaoNhat() > max){
            max = ptr->layDiemHocKyCaoNhat();
            sv = ptr;
        }
    }
    sv->hienThiSinVien();
    return sv;
};

void khoa::sapSepSVTangDanTheoLoaiGiamDanTheoNamVao(){
    int size = danhSachSinhVien.size();
    for (int i = 0; i< size; i++){
        for (int j = i+1; j<size; j++){
            if(danhSachSinhVien[i]->loaiSinhVien() > danhSachSinhVien[j]->loaiSinhVien()
            || (danhSachSinhVien[i]->loaiSinhVien() == danhSachSinhVien[j]->loaiSinhVien()
            && danhSachSinhVien[i]->layNamVaoHoc() < danhSachSinhVien[j]->layNamVaoHoc())){
                std::swap(danhSachSinhVien[i],danhSachSinhVien[j]);
            }
        }
    }
    std::cout <<"---------------------------------------------\n";
    std::cout<<"Danh sach sinh vien sau khi sap xep tang dan theo loai va giam dan theo nam vao: \n";
    for(auto ptr:danhSachSinhVien){
        ptr->hienThiSinVien();
    }
}

int khoa::SoLuongSinhVienTheoNam(uint32_t year){
    int count = 0;
    for(auto ptr:danhSachSinhVien){
        if(ptr->layNamVaoHoc() == year){
            count++;
        }
    }
    return count;
};

uint32_t khoa::layNamVaoThapNhat(){
    uint32_t min = 2025;
    for(auto ptr:danhSachSinhVien){
        if(ptr->layNamVaoHoc() < min){
            min = ptr->layNamVaoHoc();
        }
    }
    return min;
};

uint32_t khoa::layNamVaoCaoNhat(){
    uint32_t max = 2000;
    for(auto ptr:danhSachSinhVien){
        if(ptr->layNamVaoHoc() > max){
            max = ptr->layNamVaoHoc();
        }
    }
    return max;
};


void khoa::thongKeSoLuongSinhVienTheoNam(){
    for(uint32_t i = layNamVaoThapNhat(); i<= layNamVaoCaoNhat(); i++){
        if(SoLuongSinhVienTheoNam(i) > 0){
            std::cout<<"So luong sinh vien nam "<<i<<" la: "<<SoLuongSinhVienTheoNam(i)<<std::endl;
        }
    }
};



