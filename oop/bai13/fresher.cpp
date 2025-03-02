#include "fresher.h"
#include <iomanip>
#define DEBUGMODE

#define BEBUGMODE
Fresher::Fresher(unsigned int ID, std::string& FullName,std::string& BirthDay,std::string& Phone,
    std::string& Email,std::string& Employee_type,
    std::string& Graduation_date,
    std::string& Graduation_rank,
    std::string& Education)
    : Employee(ID,FullName,BirthDay,Phone,Email,Employee_type), 
    Graduation_date(Graduation_date),
    Graduation_rank(Graduation_rank),
    Education(Education)
    {
        Employee_count++;
        setCertificate();
};

Fresher::Fresher(unsigned int ID, std::string&& FullName,std::string&& BirthDay,std::string&& Phone,
    std::string&& Email,std::string&& Employee_type,
    std::string&& Graduation_date,
    std::string&& Graduation_rank,
    std::string&& Education)
    :Employee(ID,std::move(FullName),std::move(BirthDay),std::move(Phone),std::move(Email),std::move(Employee_type)), 
    Graduation_date(Graduation_date),
    Graduation_rank(Graduation_rank),
    Education(Education)
    {
        Employee_count++;
        setCertificate();
};

Fresher::~Fresher(){
    for(auto pte:ptrCer){
        #ifdef DEBUGMODE
        std::cout << "destructor Fresher called clear data Fresher and they certificate\n";
        #endif
        delete pte;
    }
    Employee_count--;
};

void Fresher::showMe(){
    showInfo();
    std::cout <<"- Type: " <<Employee_type<<" : "<< Graduation_date<< " - "<< Graduation_rank<<" - "<<Education<<std::endl;
    std::cout <<"Phone: " <<Phone<<" - Email: "<< Email << std::endl;
    showCertificate();
}