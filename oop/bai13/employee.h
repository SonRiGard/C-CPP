#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <string>
#include "certificate.h"
#include <vector>
typedef enum Employee_typeEmun{
    EnumExperience,
    EnumFresher,
    EnumIntern,
}Employee_typeEmun;

class Employee {
    protected:
        unsigned int ID;
        std::string FullName;
        std::string BirthDay;
        std::string Phone;
        std::string Email;
        std::string Employee_type;
        std::vector<Certificate*> ptrCer;
        static unsigned int Employee_count;
    public:
        
        Employee(){};
        Employee(unsigned int ID, std::string& FullName,std::string& BirthDay,std::string& Phone,std::string& Email,std::string& Employee_type)
                :ID(ID),FullName(FullName),BirthDay(BirthDay),Phone(Phone),Email(Email),Employee_type(Employee_type){};              
        
        Employee(unsigned int ID, std::string&& FullName,std::string&& BirthDay,std::string&& Phone,std::string&& Email,std::string&& Employee_type)
                :ID(ID),FullName(FullName),BirthDay(BirthDay),Phone(Phone),Email(Email),Employee_type(Employee_type){};              
        
        virtual ~Employee();
        void descreaseEmployeeCount();
        unsigned int getEmployee_count();
        unsigned int getId();
        std::string getEmployee_Type();
        virtual void showMe() = 0;
        void showInfo();
        void setCertificate();
        void showCertificate();
        void editInfor();
};  


#endif
