#include <stdio.h>
#include "math_functions.h"

int main() {
    int num = 1;
    printf("Square of %d is %d\n", num, square(num));
    printf("dequi end%d",num);
    return 0;
}

int dequi(int a){
    if(a> 5) return 0;
    else return dequi(a+1);
}