#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int getINT(){
    char buff[MAXSIZE];
    int check = 0;
    int i = 0;
    int value = 0;

    // Đọc đầu vào từ người dùng
    do {
        buff[i] = getchar();
        
        if (buff[i] == '\n') {  // Người dùng nhấn Enter
            check = 1;  // Xong, thoát vòng lặp
        } else if (buff[i] >= '0' && buff[i] <= '9') {  // Kiểm tra nếu là số
            i++;
        } else {
            printf("Vui lòng nhập lại vì bạn đã nhập sai -)): ");
            i = 0;  // Xóa dữ liệu nhập trước đó và yêu cầu nhập lại
        }
    } while (!check);

    // Chuyển mảng ký tự thành số nguyên
    for (int j = 0; j < i; j++) {
        value = value * 10 + (buff[j] - '0');
    }

    return value;
}

int main(){
    printf("Nhập số: ");
    
    int result = getINT();
    printf("Số bạn đã nhập là: %d\n", result);
    
    return 0;
}
