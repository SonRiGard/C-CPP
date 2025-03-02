#include "tuyenSinh.h"

void tuyenSinh::addSinhVien(){
    string tmpTen,tmpDiaChi,tmpKhoi;
    int tmpMucUuTien,tmpSBD;
    cout<<"Ban muon them sinh vien khoi A,B hay C: \n";
    do{
        std::cout << "Lua chon cua ban:";
        
        std::getline(std::cin,tmpKhoi);
        std::cout << std::endl;
    }while(!(tmpKhoi == "A" || tmpKhoi == "B" || tmpKhoi == "C"));

    cout<< "Nhap so bao danh:";
    tmpSBD = getUint16();
    cout<<endl;            

    cin.ignore();

    cout << "Nhap ten sinh vien: ";
    std::getline(std::cin,tmpTen);
    cout << endl;

    cout << "Nhap dia chi sinh vien: ";
    std::getline(std::cin,tmpDiaChi);
    cout << endl;

    do{
        std::cout << "Nhap muc uu tien cua sinh vien (1 -> 3) :";
        tmpMucUuTien = getInt16();
        std::cout<< std::endl;
    } while(!(tmpMucUuTien>0 && tmpMucUuTien <4));
    cout << endl;

    if(danhSachSinhVien.find(tmpSBD)!= danhSachSinhVien.end()){//check sbd này đã có chưac
        cout << "Da co SBD nay trong danh sach. Ban co muon thay the thong tin sinh vien hien tai [Y/N]";
        std::string flagReplace="";

        do{
            std::getline(std::cin,flagReplace);
            std::cout << std::endl;
        }while(!(flagReplace == "Y" || flagReplace == "N"));

        if (flagReplace == "Y"){
            switch (tmpKhoi[0])
            {
            case 'A':
                danhSachSinhVien[tmpSBD] = new sinhVienA(tmpSBD,tmpTen,tmpDiaChi,tmpMucUuTien);
                break;
            case 'B':
                danhSachSinhVien[tmpSBD] = new sinhVienB(tmpSBD,tmpTen,tmpDiaChi,tmpMucUuTien);
                break;
            case 'C':
                danhSachSinhVien[tmpSBD] = new sinhVienC(tmpSBD,tmpTen,tmpDiaChi,tmpMucUuTien);
                break;
            default:
                cout<< "Khong co sinh vien nao duoc them";
                break;
            }
        }
    }else{
        switch (tmpKhoi[0])
        {
        case 'A':
            danhSachSinhVien[tmpSBD] = new sinhVienA(tmpSBD,tmpTen,tmpDiaChi,tmpMucUuTien);
            break;
        case 'B':
            danhSachSinhVien[tmpSBD] = new sinhVienB(tmpSBD,tmpTen,tmpDiaChi,tmpMucUuTien);
            break;
        case 'C':
            danhSachSinhVien[tmpSBD] = new sinhVienC(tmpSBD,tmpTen,tmpDiaChi,tmpMucUuTien);
            break;
        default:
            cout<< "Khong co sinh vien nao duoc them";
            break;
        }
    }
};

void tuyenSinh::showSinhVien(){
    std::cout <<std::right<<std::setw(5)<< "SBD" << " :"<<"---------------------------------------------\n ";
    for (const auto &pair : danhSachSinhVien) {
        pair.second->printSinhVien();
    }
}

void tuyenSinh::seachSinhVien(int sbd){
    if(danhSachSinhVien.find(sbd) != danhSachSinhVien.end()){
        std::cout << "Tim thay nhan vien : ";
        danhSachSinhVien[sbd]->printSinhVien();
        std::cout << std::endl;
    }
    else{
        std::cout<<"Khong co sinh vien nay trong danh sach\n";
    }
};
