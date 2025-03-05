#include "managementStudents.h"
#include "controller.h"
managementStudents mnStudents;
void AddStudent(){
    mnStudents.addStudent();
}

void ShowStudents(){
    mnStudents.showInforStudents();
}

void RecruitmentStudent(){
    std::cout << "Enter the number of students to recruit:";
    int tempNeeded =0;
    do{std::cin>>tempNeeded;}
    while ((tempNeeded < 11 || tempNeeded >15));
    mnStudents.selectCandidates(tempNeeded);
}

void shownSortListNameAndPhone(){
    mnStudents.shownSortedListNameAndPhone();
}

int main(){
    controller stdController;

    stdController.addController("ADD","Add new student!",AddStudent);
    stdController.addController("SHO","Show list students!",ShowStudents);
    stdController.addController("REC","Select student to recruit!",RecruitmentStudent);
    stdController.addController("SOR","Show sorted list Name and Phone of students!",shownSortListNameAndPhone);

    stdController.run();
}

