#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include <iomanip>
typedef enum sexTypeEnum{
    female,
    male
}sexTypeEnum;
typedef enum studentTypeEnum{
    good,
    normal
}studentTypeEnum;
class Student
{
    protected:
        std::string fullname;
        std::string doB;
        std::string sex;//0 - female; 1 - male
        std::string phoneNumber;
        std::string universityName;
        std::string gradeLevel;
    public:
    Student();
    Student(std::string& fullname,std::string& doB,std::string& sex,std::string& phoneNumber,std::string& universityName,std::string& gradeLevel);
    Student(std::string&& fullname,std::string&& doB,std::string&& sex,std::string&& phoneNumber,std::string&& universityName,std::string&& gradeLevel);
    virtual ~Student();
    virtual void ShowMyInfor()=0;
    std::string getFullname();
    std::string getPhone();
    void ShowNameAndPhone();
    virtual studentTypeEnum getType() = 0;
};
#endif
