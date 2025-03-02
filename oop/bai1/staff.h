#ifndef STAFF_H_
#define STAFF_H_
#include "officer.h"

class staff : public officer {
    private:
        string task;
    public: 
        staff(string name, unsigned int age,string sex, string add, string task){
            this->fName = name;
            this->age = age;
            this->sex = sex;
            this->add = add;
            this->task = task;
        }
        void printOff()override;
};

#endif