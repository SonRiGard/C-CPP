#include <stdio.h>
#include "math_functions.h"
int dequi(int a);
int main() {
    volatile int num = 1;
    printf("Square of %d is %d\n", num, square(num));
    printf("dequi %d",dequi(num));
    return 0;
}

int dequi(int a){
    printf("a%p = ", &a);
    if(a> 5) return 0;
    else return dequi(a+1);
}

