#include "tuyenSinh.h"

typedef enum controller{
    ADD,
    SHOW,
    SEARCH,
    EXIT
}controller;

int main ()
{
    int tmpSBD;
    cout<< "---PROGRAM STARTED---\n";
    bool exit = false;
    int task = 0;
    tuyenSinh tuyenSinh2024 ;

    while (!exit){
        do{
        cout<<"Choose task:\n 0-Them sinh vien\n 1-Hien thi danh sach sinh vien\n 2-Tim kiem sinh vien theo so bao danh\n 3-Exit\n Your choice - ";
        cin >> task;
        cin.ignore();
        cout << endl;
        }
        while (task < 0 || task > 3) ;
    
        string name;int age;string sex; string address;  int type;

            switch ((controller)task)
            {
            case ADD:
                cout << "Nhap thong tin sinh vien:" << endl;    
                tuyenSinh2024.addSinhVien();
                std::cout << "-------------------------------------------------\n";
                break;
            case SHOW:
                tuyenSinh2024.showSinhVien();
                std::cout << "-------------------------------------------------\n";
                break;
            case SEARCH:
                cout << "Nhap so bao danh sinh vien muon tim kiem: ";   
                tmpSBD = getUint16();
                cout<<endl;            
                tuyenSinh2024.seachSinhVien(tmpSBD);
                cin.ignore();
            case EXIT:
                exit = 1;
                break;
            } 
    }
}