#include <iostream>
#include <string>

class Nguoi{
    private:
        std::string hoVaTen;
        int tuoi;
        std::string ngheNghiep;
        std::string cmnd;

    public:
        
        Nguoi(std::string& hoVaTen,int tuoi,std::string& ngheNghiep,std::string& cmnd);
        Nguoi(std::string&& hoVaTen,int tuoi,std::string&& ngheNghiep,std::string&& cmnd);\
        ~Nguoi();
        std::string LayhoVaTen();
        int LayTuoi();
        std::string LayNgheNghiep();
        std::string LaySoCMNN();
        void HienThiThongTinNguoi();
};