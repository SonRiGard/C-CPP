#include "hoGiaDinh.h"
#include <vector>
class khuPho {
    private:
        std::vector<hoGiaDinh*> ptrHoGiaDinh ;
    public:

        khuPho();
        ~khuPho();
        void ThemHoGiaDinh (); //return true neu them thanh cong va false neu da ton tai cmnd
        void HienThiThongTinKhuPho();
        bool KiemTraCMND(std::string cmnd);//return true neu da ton tai so cmnd nay
};