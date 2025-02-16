#include <stdio.h>
#include <stdlib.h>  // Required for malloc and free

int* createInt() {
    int* ptr = (int*)malloc(sizeof(int));  // Allocate memory on the heap
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    *ptr = 42;  // Assign value
    return ptr;  // Return pointer
}

int main() {
    int* myPtr = createInt();  // Get pointer

    if (myPtr != NULL) {
        printf("Value: %d\n", *myPtr);  // Output: 42
        free(myPtr);  // Free allocated memory
        myPtr = NULL;  // Avoid dangling pointer
    }

    return 0;
}
