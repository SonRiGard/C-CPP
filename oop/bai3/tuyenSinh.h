#ifndef TUYENSINH_H_
#define TUYENSINH_H_
#include <iostream>
#include <string>
#include <unordered_map>
#include "sinhVien.h"
#include "sinhVienA.h"
#include "sinhVienB.h"
#include "sinhVienC.h"
#include "input.h"

using namespace std;
class tuyenSinh{
    private:
        unordered_map<int, sinhVien*> danhSachSinhVien;
    public:
        void addSinhVien();
        void showSinhVien();
        void seachSinhVien(int sbd);
        void exit();

        ~tuyenSinh(){
            for (const auto &pair : danhSachSinhVien) {
                delete pair.second;
            }
        }
};
#endif