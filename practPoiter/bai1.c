#include "stdio.h"
#include "math.h"
float add (float a, float b){
    return a+b;
}
float subtract(float a, float b){
    return abs(a-b);
}
float multiply(float a, float b){
    return a*b;
}
float divide (float a, float b){
    if (b==0){
        printf("can't devide because b= 0 ");
        return 0;
    }
    else{
        return (float)a/(float)b;
    }

}



int main (){
    typedef float (*calPtr)(float, float);
    calPtr cal[4] = {add,subtract,multiply,divide};
    
    float a = 5, b=10;

    for (int i=0;i<4;i++){
        printf("resul arr[%d] =  %f \n", i,cal[i](a,b));
    }
    printf(" 1 done!\n");

}