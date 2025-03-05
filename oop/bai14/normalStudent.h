#ifndef NORMAL_STUDENT_H_
#define NORMAL_STUDENT_H_
#include <iostream>
#include "student.h"

class NormalStudent : public Student{
    private:
        int englishScore ;
        float entryTestScore;
    public:
        NormalStudent();

        NormalStudent(std::string& fullname,std::string& doB,std::string& sex,std::string& phoneNumber,
            std::string& universityName,std::string& gradeLevel,int englishScore,float entryTest);
        
        NormalStudent(std::string&& fullname,std::string&& doB,std::string&& sex,std::string&& phoneNumber,
            std::string&& universityName,std::string&& gradeLevel,int englishScore,float entryTest);

        ~NormalStudent();
        studentTypeEnum getType();
        void ShowMyInfor() override;
        float getEntryScore();
        int getEnghlishScore();
};

#endif