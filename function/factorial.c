#include "stdio.h"
int fac (int n);

int fac (int n){
    int nfac=1;
    if (n<=1) return nfac ;
    else {
        nfac = n*fac(n-1);
    }
}

int main (){
    int n =5;
    printf("factorial of %d = %d",n,fac(n));
}
