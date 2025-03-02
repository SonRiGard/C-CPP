#include <iostream>
#include <cstdint>
#include "myvector.h"
#include "input.h"
using namespace std;


void initArr (vector<uint16_t>& aptr, uint8_t number){
    for (int i = 0; i < number; i++)
    {
        aptr.push_back(getUint16());
    }
}

void printReversedWithAddresses(vector<uint16_t>& aptr) {
    cout << "Format print [index][value][ADD]:"<<endl;
    cout << "---------------------------------"<<endl;
    for (int i = aptr.getSize()-1; i > -1; i--) {
        std::cout << "[" <<i<< "]" <<"["<<aptr.getValueAtIndex(i)<<"]" <<"["<<aptr.getAddAtIndex(i)<<"]"<<endl;
    }
    std::cout << std::endl;
};

uint16_t* findMax(vector<uint16_t>& bptr){
    uint16_t* addressMax = bptr.getAddAtIndex(0);
    uint16_t max = bptr.getValueAtIndex(0);
    for(int i = 0; i < bptr.getSize(); i++){
        if(bptr.getValueAtIndex(i)> max){ 
            max = bptr.getValueAtIndex(i);
            addressMax = bptr.getAddAtIndex(i);
        };
    }
    return addressMax;
}

int main (){
    vector<uint16_t> aptr;
    cout << "how many number of arr? ";
    uint8_t numOfArr = getUint8();

    cout<< "init value for value of array elements: \n";
    initArr(aptr,numOfArr);
    cout<< "Print reverse array and them address:\n";
    printReversedWithAddresses(aptr);

    uint16_t* bptr = findMax(aptr);
    cout << "bptr = "<< bptr <<endl;
    //Auto call destructor of class vector
}
 