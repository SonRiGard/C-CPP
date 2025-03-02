#ifndef MANAGEMENT_EMPLOYEE_H_
#define MANAGEMENT_EMPLOYEE_H_
#include "employee.h"
#include "experience.h"
#include "fresher.h"
#include "intern.h"
#include "input.h"
#include <vector>

class managementEmployee {
    private:
        std::vector<Employee*> ptrEmployee;
        Employee* getPtrEmployeeById(unsigned int id);
        unsigned int getIndexEmployeeById(unsigned int id);
    public:
        managementEmployee();
        ~managementEmployee();
        void addNewEmployee();
        void editEmployeeById(unsigned int id);
        void showListEmployee();
        bool checkEmptyIdEmployee(unsigned int id);//return true if in list have this id
        unsigned int getEmployee_count();
        void findExperience();
        void findFresher();
        void findIntern();
        void deleteById(unsigned int id);     
};
#endif
