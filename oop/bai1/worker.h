#ifndef WORKER_H_
#define WORKER_H_
#include  "officer.h"

class worker : public officer{
    private: 
        int level;
    public: 
        worker(string name, unsigned int age,string sex, string add, int level){
            this->fName = name;
            this->age = age;
            this->sex = sex;
            this->add = add;
            this->level = level;
        }
        void printOff () override;
};

#endif