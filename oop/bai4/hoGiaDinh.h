#include "nguoi.h"
#include <vector>
class hoGiaDinh {
    private:
        int soNha;
        std::vector<Nguoi*> ptrThanhVien;
    public:
        hoGiaDinh();
        ~hoGiaDinh();
        void ThemThanhVien ();
        void ThemThanhVien (Nguoi* ptrNguoi);
        void CaiSoNha(int soNha);
        int GetSoLuongThanhVien();
        void HienThoThongTinNha();
        bool CheckCMNDNha(std::string cmnd);
};