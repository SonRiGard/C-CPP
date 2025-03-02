#include <stdio.h>
#include "lib.h"
#include "ctype.h"
void RegisterCallback(func func_add){
    callbackFunc = func_add;
};

void Check_Account(char* ptr, uint8_t lenght){
        // Kiểm tra độ dài chuỗi
        if (lenght > 10) {
            if (callbackFunc != NULL) {
                callbackFunc(LENGHT_INVALID);
            }
            return;
        }
        // Kiểm tra ký tự hợp lệ (chỉ cho phép chữ và số)
        for (uint8_t i = 0; i < lenght; i++) {
            if (!isalnum(ptr[i])) {
                if (callbackFunc != NULL) {
                    callbackFunc(CHAR_INVALID);
                }
                return;
            }
        }
        // Nếu không có lỗi nào
        if (callbackFunc != NULL) {
            callbackFunc(CORRECT);
        }
};


