#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// Hàm để xóa tất cả ký tự còn lại trong bộ đệm
void flush_input_buffer() {
    char ch;
    int count=0;
    while ((ch = getchar()) != '\n' && ch != EOF );  // Đọc và bỏ qua tất cả đến khi gặp '\n' hoặc EOF
}

// Hàm nhập số nguyên và kiểm tra đầu vào
int getInt() {
    char buff[MAXSIZE];
    int check = 0; // điều kiện thoát chương trình
    int i = 0; // biến count 
    int value = 0;
    do {
        buff[i] = getchar();
        
        if (buff[i] == '\n') {  // Người dùng nhấn Enter
            if (i == 0) {
                printf("No input value. Input again: ");
            } else {
                check = 1;  // Đã nhập đủ dữ liệu, thoát vòng lặp
            }
        } else if (buff[i] < '0' || buff[i] > '9' || buff[i] == ' ') {  // Kiểm tra nếu không phải số
                flush_input_buffer();
                printf("Input number again: )) ");
                i = 0;  // Xóa dữ liệu nhập trước đó và yêu cầu nhập lại
                value = 0;
                continue;
        } else {
            value = value * 10 + (buff[i] - '0');  // Tính toán giá trị
        }

        i++;  // Tiến đến ký tự tiếp theo
    } while (!check);

    return value;
}

char getChar() {
    char input;
    int check = 0;

    do {
        input = getchar();  // Đọc một ký tự

        if (input == '\n') {  // Nếu chỉ nhấn Enter mà không nhập ký tự
            printf("No input detected. Please enter a character from 'a' to 'z': ");
        } else if (input >= 'a' && input <= 'z') {  // Nếu ký tự hợp lệ
            if (getchar() == '\n') {  // Kiểm tra xem còn ký tự nào khác trong bộ đệm không
                check = 1;  // Nếu không còn ký tự khác, chấp nhận giá trị
            } else {  
                printf("Invalid input. Please enter only one character from 'a' to 'z': ");
                flush_input_buffer();  // Xóa bộ đệm để tránh kẹt input
            }
        } else {  // Nếu nhập ký tự không hợp lệ
            printf("Invalid input. Please enter a character from 'a' to 'z': ");
            flush_input_buffer();  // Xóa bộ đệm để yêu cầu nhập lại từ đầu
        }

    } while (!check);

    return input;
}

