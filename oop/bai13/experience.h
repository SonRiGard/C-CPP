#ifndef EXPERIENCE_H_
#define EXPERIENCE_H_
#include "employee.h"
#include <iostream>
#include <utility>

class Experience:public Employee {
    private:
        int ExpInYear;
        std::string ProSkill;
    public:
        Experience(){};
        Experience(unsigned int ID, std::string& FullName,std::string& BirthDay,std::string& Phone,
            std::string& Email,std::string& Employee_type,
            int ExpInYear,
            std::string& ProSkill);
        
        Experience(unsigned int ID, std::string&& FullName,std::string&& BirthDay,std::string&& Phone,
            std::string&& Email,std::string&& Employee_type,
            int ExpInYear,
            std::string&& ProSkill);

        void showMe() override;
        ~Experience();
};
#endif

