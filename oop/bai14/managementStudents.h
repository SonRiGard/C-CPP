#ifndef MANAGEMENT_STUDENTS_H_
#define MANAGEMENT_STUDENTS_H_
#include "goodStudent.h"
#include "normalStudent.h"
#include <vector>
class managementStudents{
    private:
        std::vector<Student*> ptrStudents;
    public:
        managementStudents();
        ~managementStudents();
        void showInforStudents();
        void shownSortedListNameAndPhone();     
        void addStudent();
        void sortStudents();
        void selectCandidates(int n);
        void autoAddStudent();
    
};
#endif