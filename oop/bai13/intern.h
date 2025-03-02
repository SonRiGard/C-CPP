#ifndef INTERN_H_
#define INTERN_H_
#include "employee.h"
#include <utility>

class Intern : public Employee{
    private:
        std::string Majors;
        int Semester;
        std::string University_name;
    public:
    ~Intern();
    Intern(unsigned int ID, std::string& FullName,std::string& BirthDay,std::string& Phone,
        std::string& Email,std::string& Employee_type,
        std::string& Majors,
        int Semester,
        std::string& University_name);

    Intern(unsigned int ID, std::string&& FullName,std::string&& BirthDay,std::string&& Phone,
        std::string&& Email,std::string&& Employee_type,
        std::string&& Majors,
        int Semester,
        std::string&& University_name);

        void showMe() override;
};
#endif