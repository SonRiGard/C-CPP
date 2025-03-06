#include "student.h"

Student::Student(){

};

Student::Student(const std::string& fullname,const std::string& doB,const std::string& sex,const std::string& phoneNumber,
    const std::string& universityName,const std::string& gradeLevel)
        :fullname(fullname),doB(doB),sex(sex),phoneNumber(phoneNumber),universityName(universityName),gradeLevel(gradeLevel)
{

};

Student::Student(std::string&& fullname,std::string&& doB,std::string&& sex,std::string&& phoneNumber,
        std::string&& universityName,std::string&& gradeLevel)
        :fullname(fullname),doB(doB),sex(sex),phoneNumber(phoneNumber),universityName(universityName),gradeLevel(gradeLevel)
{

};

Student::~Student(){

};

void Student::ShowNameAndPhone(){
    std::cout << "------------------------\n Student: ";
    std::cout <<fullname << " - Phone: "<<phoneNumber<<std::endl;
};

std::string Student::getFullname(){
    return fullname;
};
std::string Student::getPhone(){
    return phoneNumber;
};