#ifndef OFFICER_H_
#define OFFICER_H_
#include "officer.h"

class engineer : public officer{
    private: 
        string  branch;
    public: 
        engineer(string name, unsigned int age,string sex, string add, string branch){
            this->fName = name;
            this->age = age;
            this->sex = sex;
            this->add = add;
            this->branch = branch;
        }
        void printOff() override ;
};

#endif