#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
#include <string.h>
#include "myVector.h"

using namespace std;
class officer {
    protected:
        string fName;
        unsigned int age;
        string sex;
        string add;
    public:
        virtual void printOff (){}; 

        string getName(){
            return this->fName;
        };
};
#endif