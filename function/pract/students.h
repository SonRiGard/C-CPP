#pragma once
typedef struct student_t student_t;

student_t* create_students(int n);
student_t* add_student(int n, student_t* obj);
void print_students(int n, student_t* obj, int ID_width = 2,int name_width = 20, int age_width = 10, int score_width = 10);
void sortByAvgScore (student_t* obj, int n);
student_t* create_students_auto(int n);
int SeachByAvgScore (int target, student_t *obj, int n);
int& editAge (student_t *obj, int id);
int& editAvgScore(student_t *obj, int id);
int calAvgScore (student_t* obj, int id , int count, ...);
