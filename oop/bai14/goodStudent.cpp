#include "goodStudent.h"
#include <string>
#include <iostream>
#include <utility>
GoodStudent::GoodStudent(){

};

GoodStudent::GoodStudent(std::string& fullname,std::string& doB,std::string& sex,std::string& phoneNumber,
    std::string& universityName,std::string& gradeLevel,float gpa,std::string& bestRewardName)
    :Student(fullname, doB, sex, phoneNumber,universityName, gradeLevel),
    gpa(gpa),bestRewardName(bestRewardName)
{

};

GoodStudent::GoodStudent(std::string&& fullname,std::string&& doB,std::string&& sex,std::string&& phoneNumber,
    std::string&& universityName,std::string&& gradeLevel,float gpa,std::string&& bestRewardName)
    :Student(std::move(fullname), std::move(doB), std::move(sex), std::move(phoneNumber),std::move(universityName), std::move(gradeLevel)),
    gpa(gpa),bestRewardName(bestRewardName)
{
};

GoodStudent::~GoodStudent()
{
};

void GoodStudent::ShowMyInfor(){
    std::cout<<"--------------------------------------\n";
    std::cout <<"Student - "<<fullname<< " | "<<doB<<" | "<<sex;
    std::cout << " | " << phoneNumber <<std::endl 
    << " | " << universityName << " | "<< gradeLevel<<" | gpa = " <<gpa<<" | "<<bestRewardName<<std::endl;
};

studentTypeEnum GoodStudent::getType(){
    return good;
};

float GoodStudent::getGPA(){
    return gpa;
};
