#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stdint.h>

class ketQuaHocTap {
private:
    int kyHoc;
    float diemTrungBinh;

public:
    ketQuaHocTap();
    ketQuaHocTap(int tenKy, float diemTrungBinh);
    ~ketQuaHocTap();

    int layKyHoc();
    
    float getDiemTrungBinh();
};
