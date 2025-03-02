#include <stdint.h>
#include "input.h"
using namespace std;

void absoluteValue(uint8_t *data){
    if(data == NULL) return;
    if (data[0]>=data[1]){
        data[2]=  (data[0] - data[1]);
    }else data[2] =  (data[1] - data[0]);
}
int main (){
    uint8_t arr[3];
    while (1)
    {
        cout << "Program cal absolute of 2 value: \n a = "; arr[0]= getUint8();
        cout << "  b = "; arr[1] = getUint8(); cout << endl;
        absoluteValue(arr);
        cout << "|a-b| = " ;
        cout << (int)arr[2] ;
        cout << endl; 
    }
}
