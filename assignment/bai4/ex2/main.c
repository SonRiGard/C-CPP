#include <stdio.h>
#include "lib.h"
#include <string.h>

void AccountStatusHandler(status_enum_t status) {
    switch (status) {
        case CORRECT:
            printf("Account correct!\n");
            break;
        case CHAR_INVALID:
            printf("ERR: Account has invalid character.!\n");
            break;
        case LENGHT_INVALID:
            printf("ER: Account > 10 characters!\n");
            break;
        default:
            printf("ERR h!\n");
            break;
    }
}

int main() {
    char arr[20]; 

    RegisterCallback(AccountStatusHandler);

    while (1) {
        printf("Enter accout (enter 'exit' to exit): ");
        fgets(arr, sizeof(arr), stdin);

        // Loại bỏ ký tự xuống dòng '\n' nếu có
        arr[strcspn(arr, "\n")] = 0;

        // Kiểm tra thoát chương trình
        if (strcmp(arr, "exit") == 0) {
            break;
        }
        Check_Account(arr, strlen(arr));
    }

    return 0;
}
