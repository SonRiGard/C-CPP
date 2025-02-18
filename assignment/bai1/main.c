#include <stdio.h>
#include "intManagment.h"
#include "input.h"


int main(){
    int exit = 0;
    intManagment* ObjIntManagment = creat_ptr_managment();
    while (!exit) {
        printf("CT Quản Lý dãy số bằng mảng\n");
        printf("Hướng dẫn sử dụng:\n");
        printf(" - Nhập 'c' để tạo mảng mới\n");
        printf(" - Nhập 'p' để in dãy số\n");
        printf(" - Nhập 'i' để thêm phần tử vào dãy\n");
        printf(" - Nhập 'd' để xóa phần tử khỏi dãy\n");
        printf(" - Nhập 's' để sắp xếp tăng dần\n");
        printf(" - Nhập 'x' để sắp xếp giảm dần\n");
        printf(" - Nhập 't' để tìm kiếm số trong dãy\n");
        printf(" - Nhập 'e' để thoát chương trình\n");
        printf(" - Nhập lựa chọn của bạn: ");
        char choice = getChar();
        int num;
            switch (choice) {
                case 'c':
                    printf("\n nhập số lượng phần tử trong mảng : ");
                    num = getInt();
                    initArr(ObjIntManagment,num);
                    break;
                case 'p':
                    printListArr(ObjIntManagment);
                    break;
                case 'i': {
                    printf("Nhập index cần thêm: ");
                    int index = getInt();
                    printf("\n");

                    printf("Nhập value cần thêm: ");
                    int value = getInt();
                    printf("\n");

                    if (insertAtIndex(ObjIntManagment,index,value )) {
                        printf("Thêm thành công!\n");
                    }
                    break;
                }
                case 'd': {
                    printf("Nhập index cần xóa: ");
                    int index = getInt();
                    if (deleteAtIndex(ObjIntManagment, index)) {
                        printf("Xóa thành công!\n");
                    }
                    break;
                }
                case 's':
                    sortAscending(ObjIntManagment);
                    printf("Dãy đã được sắp xếp tăng dần.\n");
                    break;
                case 'x':
                    sortDescending(ObjIntManagment);
                    printf("Dãy đã được sắp xếp giảm dần.\n");
                    break;
                case 't': {
                    printf(" Nhập số cần tìm kiếm: ");
                    int x = getInt();
                    printf("\n");
                    if (checkValue(ObjIntManagment, x)) {
                        printf("Số %d có trong dãy.\n", x);
                    } else {
                        printf("Số %d không có trong dãy.\n", x);
                    }
                    break;
                }
                case 'e':
                    printf("Thoát chương trình.\n");
                    exit = 1;
                    return 0;
                default:
                    printf("Lựa chọn không hợp lệ! Vui lòng thử lại.\n");
                }
        }
        return 0;
                
}