#include "ketQuaHocTap.hpp"

ketQuaHocTap::ketQuaHocTap(){
    this->kyHoc = 0;
    this->diemTrungBinh = 0;
};

ketQuaHocTap::ketQuaHocTap(int kyHoc, float diemTrungBinh){
    this->kyHoc = kyHoc;
    this->diemTrungBinh = diemTrungBinh;
};

ketQuaHocTap::~ketQuaHocTap(){
    std::cout << "destructor of ketQuaHocTap\n";
};

int ketQuaHocTap::layKyHoc(){
    return this->kyHoc;
};

float ketQuaHocTap::getDiemTrungBinh(){
    return this->diemTrungBinh;
};

