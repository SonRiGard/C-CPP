#include "sinhVien.hpp"
#include "exception.hpp"
#include "sinhVienChinhQuy.hpp"

sinhVien::sinhVien(){
};

sinhVien::sinhVien(std::string& maSV, std::string& hoTen, std::string& doB, uint16_t namVaoHoc, float diemDauVao)
    :maSinhVien(maSV),hoTen(hoTen),doB(doB),namVaoHoc(namVaoHoc),diemDauVao(diemDauVao)
{
    #ifdef AUTO_INPUT_MODE
    autoNhapDiem();
    #endif

    #ifdef MANUAL_INPUT_MODE
    nhapDiem();
    #endif
};

//move constructor
sinhVien::sinhVien(std::string&& maSV, std::string&& hoTen, std::string&& doB, uint16_t& namVaoHoc, float& diemDauVao)
    :maSinhVien(maSV),hoTen(hoTen),doB(doB),namVaoHoc(namVaoHoc),diemDauVao(diemDauVao)
{
    // nhapDiem();
    autoNhapDiem();
};

//deep copy constructor
sinhVien::sinhVien(const sinhVien& other)
: maSinhVien(other.maSinhVien), hoTen(other.hoTen), doB(other.doB),
  namVaoHoc(other.namVaoHoc), diemDauVao(other.diemDauVao), bangDiem(other.bangDiem) {}
//des
sinhVien::~sinhVien(){
    for(auto ptr:bangDiem){
        delete ptr;
    }
}

void sinhVien::nhapDiem(){
    bool isContinue = true;
    while(isContinue){
        std::string choice; int kyhoc;float diemTrungBinh;
        std::cout << "Ban co muon nhap diem khong? (y/n): ";
        do{ 
            std::cin >> choice;}
        while(choice != "y" && choice != "n");

        if(choice == "n"){
            isContinue = false;
            break;
        }

        try{

            std::cout << "nhap ky hoc:";
            std::cin >> kyhoc;
            for(auto ptr:bangDiem){
                if(ptr->layKyHoc() == kyhoc){
                    throw std::runtime_error("Ky hoc da ton tai!");
                }
            }
            
            InvalidSemesterException(kyhoc);
            std::cout << "nhap diem trung binh:";
 
            std::cin >> diemTrungBinh;
            std::cin.ignore();
            InvalidEntryScoreException(diemTrungBinh);
            
        }catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
        bangDiem.push_back(new ketQuaHocTap(kyhoc,diemTrungBinh));
    }
};

void sinhVien::autoNhapDiem() {
    int soKyHoc = 1 + std::rand() % 8; 
    bangDiem.clear(); 

    for (int i = 1; i <= soKyHoc; i++) {
        int kyHoc = i; 
        float diemTrungBinh = 5.0 + static_cast<float>(std::rand() % 51) / 10;

        bangDiem.push_back(new ketQuaHocTap(kyHoc, diemTrungBinh));

        std::cout << "Da them diem tu dong: Ky hoc " << kyHoc 
                  << " - Diem trung binh: " << diemTrungBinh << std::endl;
    }
}

void sinhVien::xuatDiem(){
    if(bangDiem.size() == 0){
        std::cout << "Sinh vien chua co diem!\n";
        return;
    }
    for(auto ptr:bangDiem){
        std::cout << "Ky hoc: " << ptr->layKyHoc() << " - Diem trung binh: " << ptr->getDiemTrungBinh() << std::endl;
    }
};

std::string sinhVien::layMaSinhVien(){
    return maSinhVien;
}

float sinhVien::layDiemTheoKy(){
    int kyhoc;
    std::cout << "Nhap ky hoc can xem diem: ";
    std::cin >> kyhoc;
    for(auto ptr:bangDiem){
        if(ptr->layKyHoc() == kyhoc){
            return ptr->getDiemTrungBinh();
        }
    }
    return 0;
};

float sinhVien::layDiemTheoKy(int kyHoc){
    for(auto ptr:bangDiem){
        if(ptr->layKyHoc() == kyHoc){
            return ptr->getDiemTrungBinh();
        }
    }
    return 0;
};

float sinhVien::layDiemDauVao(){
    return diemDauVao;
};

float sinhVien::layDiemHocKyGanNhat(){
    int maxIndex = 0;
    int size = bangDiem.size();
    for (int i = 1; i < size; i++){
        if(bangDiem[i]->layKyHoc() > bangDiem[maxIndex]->layKyHoc()){
            maxIndex = i;
        }
    }
    return bangDiem[maxIndex]->getDiemTrungBinh();
};

float sinhVien::layDiemHocKyCaoNhat(){
    int maxIndex = 0;
    int size = bangDiem.size();
    for (int i = 1; i < size; i++){
        if(bangDiem[i]->getDiemTrungBinh() > bangDiem[maxIndex]->getDiemTrungBinh()){
            maxIndex = i;
        }
    }
    return bangDiem[maxIndex]->getDiemTrungBinh();
};

uint16_t sinhVien::layNamVaoHoc(){
    return namVaoHoc;
};