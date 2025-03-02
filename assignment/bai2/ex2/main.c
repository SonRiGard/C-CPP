#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

bool allocate10Bytes(uint8_t *outPtr) {
    uint8_t *tmpPtr = (uint8_t *)malloc(sizeof(uint8_t) * 10);  
    printf("Memory allocated at address %p\n", (uint8_t*)tmpPtr);

    *((uint8_t**) outPtr) = tmpPtr;

    if(tmpPtr == NULL)return false;
    return true;
}

int main() {
    uint8_t *ptr = NULL;
    printf("Memory address -1 %p\n", &ptr);
    if(allocate10Bytes((uint8_t* )&ptr)){
        printf("Memory address -2 %p\n", &ptr);
        printf("Memory allocated at address %p\n", ptr);
    } else {
        printf("Memory allocation failed!\n");
    }
    free(ptr);
    return 0;
}