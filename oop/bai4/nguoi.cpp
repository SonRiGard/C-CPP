#include "stdio.h"
#include <string>
class nguoi{
    protected:
        std::string hoVaTen;
        int tuoi;
        std::string ngheNghiep;
        std::string cmnn;
    public:
        nguoi(std::string hoVaTen,int tuoi,std::string ngheNghiep,std::string cmnn)
            :hoVaTen(hoVaTen),tuoi(tuoi),ngheNghiep(ngheNghiep),cmnn(cmnn)
        {
            
        }
}