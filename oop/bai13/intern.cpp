#include "intern.h"
#include <iomanip>
#define DEBUGMODE

Intern::~Intern(){
    for(auto pte:ptrCer){
        #ifdef DEBUGMODE
        std::cout << "destructor Intern called clear data Intern and they certificate\n";
        #endif
        delete pte;
    }
    Employee_count--;
}
Intern::Intern(unsigned int ID, std::string& FullName,std::string& BirthDay,std::string& Phone,
    std::string& Email,std::string& Employee_type,
    std::string& Majors,
    int Semester,
    std::string& University_name): 
    Employee(ID,FullName,BirthDay,Phone,Email,Employee_type), 
    Majors(Majors),
    Semester(Semester),
    University_name(University_name)
    {   
        Employee_count++;
        setCertificate();
    };

Intern::Intern(unsigned int ID, std::string&& FullName,std::string&& BirthDay,std::string&& Phone,
    std::string&& Email,std::string&& Employee_type,
    std::string&& Majors,
    int Semester,
    std::string&& University_name): 
    Employee(ID,std::move(FullName),std::move(BirthDay),std::move(Phone),std::move(Email),std::move(Employee_type)), 
    Majors(Majors),
    Semester(Semester),
    University_name(University_name)
    {   
        Employee_count++;
        setCertificate();
    };

void Intern::showMe(){
    showInfo();
    std::cout <<"Phone: "<<Phone<<"- Email: "<< Email << std::endl;
    std::cout <<"Certificate: ";
    showCertificate();
}
