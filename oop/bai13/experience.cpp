#include "experience.h"
#include <iomanip>
#include <utility>
#define DEBUGMODE

Experience::Experience(unsigned int ID, std::string& FullName,std::string& BirthDay,std::string& Phone,
    std::string& Email,std::string& Employee_type,int ExpInYear,std::string& ProSkill)
    : Employee(ID,FullName,BirthDay,Phone,Email,Employee_type), 
    ExpInYear(ExpInYear),
    ProSkill(ProSkill)
    {
        Employee_count++;
        setCertificate();
};

Experience::Experience(unsigned int ID, std::string&& FullName,std::string&& BirthDay,std::string&& Phone,
    std::string&& Email,std::string&& Employee_type,int ExpInYear,std::string&& ProSkill)
    : Employee(ID,std::move(FullName),std::move(BirthDay),std::move(Phone),std::move(Email),std::move(Employee_type)),
    ExpInYear(ExpInYear),
    ProSkill(std::move(ProSkill))
    {
        Employee_count++;
        setCertificate();
};
    
Experience::~Experience(){
    for(auto pte:ptrCer){
        #ifdef DEBUGMODE
        std::cout << "destructor Experience called clear data Experience and they certificate\n";
        #endif
        delete pte;
    }
    Employee_count--; 
};

void Experience::showMe(){
    showInfo();
    std::cout <<"- Type :" <<Employee_type<<":"<< ExpInYear<< "years - "<< ProSkill<<std::endl;
    std::cout <<"Certificate: ";
    showCertificate();
}




