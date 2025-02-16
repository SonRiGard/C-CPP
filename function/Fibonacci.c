#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;  // Base case
    if (n == 1) return 1;  // Base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

int main() {
    int num = 7;
    printf("Fibonacci(%d) = %d\n", num, fibonacci(num));
    return 0;
}
