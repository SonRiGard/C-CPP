#include <stdio.h>
#include <stdarg.h>

// Hàm tính tổng với số lượng tham số không cố định
int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

int main() {
    printf("Sum: %d\n", sum(3, 1, 2, 3)); // Output: Sum: 6
    return 0;
}
