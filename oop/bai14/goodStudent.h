#ifndef GOOD_STUDENT_H_
#define GOOD_STUDENT_H_
#include <iostream>
#include <string.h>
#include "student.h"

class GoodStudent:public Student {
    private:
        float gpa;
        std::string bestRewardName;
    public:
        GoodStudent();
        GoodStudent(std::string& fullname,std::string& doB,std::string& sex,std::string& phoneNumber,
            std::string& universityName,std::string& gradeLevel,float gpa,std::string& bestRewardName);
        GoodStudent(std::string&& fullname,std::string&& doB,std::string&& sex,std::string&& phoneNumber,
            std::string&& universityName,std::string&& gradeLevel,float gpa,std::string&& bestRewardName);
        ~GoodStudent();
        void ShowMyInfor() override;
        studentTypeEnum getType();
        float getGPA();
};

#endif