#include <stdio.h>

void processData(void *data, void (*callback)(void *)) {
    callback(data); // Gọi hàm callback
}

void printInteger(void *data) {
    printf("Integer: %d\n", *(int*)data);
}

void printFloat(void *data) {
    printf("Float: %f\n", *(float*)data);
}

int main() {
    int x = 10;
    float y = 3.14;
    processData(&x, printInteger);
    processData(&y, printFloat);
    return 0;
}
