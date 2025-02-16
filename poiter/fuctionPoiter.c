#include <stdio.h>

void sayHello() {
    printf("Hello, World!\n");
}

int main() {
    void (*funcPtr)(); // Declare function pointer
    funcPtr = sayHello; // Assign function address
    funcPtr(); // Call function
    return 0;
}
