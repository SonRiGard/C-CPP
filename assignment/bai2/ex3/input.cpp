#include <iostream>
#include <cstdint>
using namespace std;

// #define DEBUG
#define MAX_UINT8 255
#define MIN_UINT8 0
#define MAX_INT16 32767
#define MIN_INT16 -32768
#define MAX_UINT16 65535
#define MIN_UINT16 0
uint8_t getUint8() {
    uint8_t num;
    while (true) {
        int temp;  // Biến tạm thời để lưu giá trị nhập vào
    
        while (true) {
            #ifdef DEBUG
            cout << "Enter a number ("<<MIN_UINT8<<"-"<<MAX_UINT8<<"): ";
            #endif
            // Kiểm tra đầu vào là số nguyên
            if (cin >> temp) {
                // Kiểm tra nếu giá trị nằm trong phạm vi của uint8_t
                if (temp >= MIN_UINT8 && temp <= MAX_UINT8) {
                    #ifdef DEBUG
                    cout << "valid value"<< endl;
                    #endif
                    return static_cast<uint8_t>(temp);  // Chuyển đổi và trả về giá trị hợp lệ
                } else {
                    cout << "Error: Number must be between "<<MIN_UINT8<<" - "<<MAX_UINT8<< "\n";
                    cout << "enter again: ";
                }
            } else {
                // Nếu không phải số (như chữ cái), xử lý lỗi
                cout << "Error: Invalid input. Please enter a valid number.\n";
                cin.clear();  // Xóa lỗi trạng thái của cin
                char ch;
                while (cin.get(ch) && ch != '\n');  // Lặp lại cho đến khi gặp ký tự xuống dòng
            }
        }
    }
}

int16_t getInt16() {
    int temp;  // Biến tạm thời để lưu giá trị nhập vào
    
    while (true) {
        cout << "Enter a number ("<<MIN_INT16<<"add"<<MAX_INT16<< "): ";
        
        // Kiểm tra đầu vào là số nguyên
        if (cin >> temp) {
            // Kiểm tra nếu giá trị nằm trong phạm vi của int16_t
            if (temp >= MIN_INT16 && temp <= MAX_INT16) {
                #ifdef DEBUG
                cout << "Valid value" << endl;
                #endif
                return static_cast<int16_t>(temp);  // Chuyển đổi và trả về giá trị hợp lệ
            } else {
                cout << "Error: Number must be between "<<MIN_INT16<<"add"<<MAX_INT16<< ".\n";
            }
        } else {
            // Nếu không phải số (như chữ cái), xử lý lỗi
            cout << "Error: Invalid input. Please enter a valid number.\n";
            cin.clear();  // Xóa lỗi trạng thái của cin

            char ch;
            while (cin.get(ch) && ch != '\n');  // Lặp lại cho đến khi gặp ký tự xuống dòng
        }
    }
}

uint16_t getUint16() {
    int temp;  // Biến tạm thời để lưu giá trị nhập vào

    while (true) {
        cout << "Enter a number ("<<MIN_INT16<<"-"<<MAX_INT16<< "): ";

        // Kiểm tra đầu vào là số nguyên
        if (cin >> temp) {
            // Kiểm tra nếu giá trị nằm trong phạm vi của uint16_t
            if (temp >= MIN_UINT16 && temp <= MAX_UINT16) {
                cout << "Valid value" << endl;
                return static_cast<uint16_t>(temp);  // Chuyển đổi và trả về giá trị hợp lệ
            } else {
                cout << "Error: Number must be between "<<MIN_UINT16<<"add"<<MAX_UINT16<< ".\n";
            }
        } else {
            // Nếu không phải số (như chữ cái), xử lý lỗi
            cout << "Error: Invalid input. Please enter a valid number.\n";
            cin.clear();  // Xóa lỗi trạng thái của cin

            char ch;
            while (cin.get(ch) && ch != '\n');  // Đọc và bỏ qua ký tự không hợp lệ trong bộ đệm
        }
    }
}
