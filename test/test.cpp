#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    printf("Giá trị của x: %d\n", x);
    printf("Giá trị của x thông qua *p: %d\n", *p);
    printf("Giá trị của x thông qua **pp: %d\n", **pp);

    printf("Địa chỉ của x: %p\n", (void*)&x);
    printf("Giá trị của p (địa chỉ của x): %p\n", (void*)p);
    printf("Giá trị của pp (địa chỉ của p): %p\n", (void*)pp);
    
    return 0;
}
