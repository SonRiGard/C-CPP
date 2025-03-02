#ifndef FRESHER_H_
#define FRESHER_H_
#include "employee.h"
#include <utility>

class Fresher : public Employee {
    private:
        std::string Graduation_date;
        std::string Graduation_rank;
        std::string Education;
    public:
        ~Fresher();
        Fresher(unsigned int ID, std::string& FullName,std::string& BirthDay,std::string& Phone,
            std::string& Email,std::string& Employee_type,
            std::string& Graduation_date,
            std::string& Graduation_rank,
            std::string& Education);
        Fresher(unsigned int ID, std::string&& FullName,std::string&& BirthDay,std::string&& Phone,
            std::string&& Email,std::string&& Employee_type,
            std::string&& Graduation_date,
            std::string&& Graduation_rank,
            std::string&& Education);
        void showMe() override;


};
#endif