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
        void printOff () override {
            cout << "name: "<< fName << " age: "<< age<<" ;sex: "<< sex <<" ;address: "<< add << " ;level: " << level << endl; 
        }
};

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
        void printOff() override {
            cout << "name: "<< fName << " age: "<< age<<" ;sex: "<< sex <<" ;address: "<< add << " ;branch: " << branch << endl; 
        }
};

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
        void printOff()override {
            cout << "name: "<< fName << " age: "<< age<<" ;sex: "<< sex <<" ;address: "<< add << " ;task: " << task << endl; 
        }
};

class managmentOfficer {
    private:
        vector<officer*> listOfficer; 
        
    public:
        virtual int addNew(officer* obj);
        void searchByName(string name);
        void shownList();
        void exit ();

        ~managmentOfficer() {
            std::cout << "Đang hủy danh sách cán bộ..." << std::endl;
            for (auto obj : listOfficer) {
                std::cout << "Xóa: " << std::endl;
                delete obj;
            }
            listOfficer.clear();
        }
};

#endif