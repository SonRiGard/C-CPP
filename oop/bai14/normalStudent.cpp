#include "normalStudent.h"

NormalStudent::NormalStudent(){//defalse constructor

};

NormalStudent::NormalStudent(std::string& fullname,std::string& doB,std::string& sex,std::string& phoneNumber,//normal const
    std::string& universityName,std::string& gradeLevel,int englishScore,float entryTestScore)
    :Student(fullname, doB, sex, phoneNumber,universityName, gradeLevel),
    englishScore(englishScore),entryTestScore(entryTestScore)
{

}

NormalStudent::NormalStudent(std::string&& fullname,std::string&& doB,std::string&& sex,std::string&& phoneNumber,//move const
    std::string&& universityName,std::string&& gradeLevel,int englishScore,float entryTest)
    :Student(std::move(fullname), std::move(doB),  std::move(sex), std::move(phoneNumber),std::move(universityName), std::move(gradeLevel)),
    englishScore(englishScore),entryTestScore(entryTest)
{

};

NormalStudent::~NormalStudent(){

};

void NormalStudent::ShowMyInfor(){
    std::cout<<"-----------------------------------------------------------------\n";
    std::cout <<"Student - "<<fullname<< " | "<<doB<<" | " << sex;
    std::cout << " | " << phoneNumber <<std::endl 
    << " | " << universityName << " | "<< gradeLevel<<" | entryTestScore = " <<englishScore<<" | entryTestScore = "<<entryTestScore<<std::endl;
};

studentTypeEnum NormalStudent::getType(){
    return normal;
};

float NormalStudent::getEntryScore(){
    return entryTestScore;
};

int NormalStudent::getEnghlishScore(){
    return englishScore;
};