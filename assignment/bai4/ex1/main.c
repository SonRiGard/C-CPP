#include <stdio.h>

int main() {
    char *c;
    char **s;
    char foo[] = "Hello World";

    s = (char **)&foo; // Ép kiểu từ char* sang char**

    printf("s is %s\n", (char *)s); // In ra chuỗi thông qua ép kiểu
    c = (char*)foo; // Lấy ký tự đầu tiên
    printf("s[0] is %c\n", *c); // In ra ký tự đầu tiên 'H'
    
    return 0;
}
