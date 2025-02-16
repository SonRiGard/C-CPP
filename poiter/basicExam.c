#include <stdio.h>

int main() {
    int *p1;
    char *p2;
    double *p3;

    printf("Size of int pointer: %zu bytes\n", sizeof(p1));
    printf("Size of char pointer: %zu bytes\n", sizeof(p2));
    printf("Size of double pointer: %zu bytes\n", sizeof(p3));

    return 0;
}
