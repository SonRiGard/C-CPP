#include <iostream>
#include "managementEmployee.h"
#include "controller.h"
#include "input.h"
managementEmployee manageEmp ;

void addNewEmployee(){
    manageEmp.addNewEmployee();
}
void deleteEmployee(){
    std::cout << "Enter ID of Employee need delete:";
    unsigned int id = getUint16();
    std::cin.ignore();
    manageEmp.deleteById(id);
}
void getExperience(){
    manageEmp.findExperience();
}
void getFresher(){
    manageEmp.findFresher();
}
void getIntern(){
    manageEmp.findIntern();
}
void showListEMp(){
    manageEmp.showListEmployee();
}

int main (){
    controller controlEmp;
    controlEmp.addController("ADD","Add new Employee",addNewEmployee);
    controlEmp.addController("DEL","Delete Employee at ID",deleteEmployee);
    controlEmp.addController("EXP","Find Experience type in list",getExperience);
    controlEmp.addController("FRE","Find Fresher type in list",getFresher);
    controlEmp.addController("INT","Find Intern type in list",getIntern);
    controlEmp.addController("PRI","Print list Employee",showListEMp);

    controlEmp.run();
}   





