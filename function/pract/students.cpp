#include <iostream>
#include <string>
#include "students.h"
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdarg.h>
using namespace std;

struct student_t{
    int ID;
    char name[20];
    int age;
    int avg_score;
};

student_t* create_students(int n) {
    student_t* arr_std = new student_t[n];

    cout << "Press any button to continue" << endl;
    cin.ignore();  // Xóa bộ nhớ đệm trước khi nhập đầu tiên

    for (int i = 0; i < n; i++) {
        cout << "Student number: " << i + 1 << ":\n";
        
        cout << "ID = " << i <<endl;
        arr_std[i].ID = i;
        cout << "Name: ";
        cin >> ws;  // Loại bỏ khoảng trắng và ký tự xuống dòng còn sót lại
        cin.getline(arr_std[i].name, 20);

        cout << "Age: ";
        cin >> arr_std[i].age;

        cout << "Avg score: ";
        cin >> arr_std[i].avg_score;

        cin.ignore();  // Xóa ký tự xuống dòng sau khi nhập số để tránh lỗi ở vòng lặp tiếp theo
    }

    return arr_std;
}

student_t* create_students_auto(int n) {
    if (n <= 0) return nullptr;  // Kiểm tra số lượng hợp lệ

    student_t* arr_std = new student_t[n];  // Cấp phát bộ nhớ động
    srand(time(0));  // Khởi tạo seed cho hàm rand()

    for (int i = 0; i < n; i++) {
        arr_std[i].ID = i;  // ID bắt đầu từ 0
        strcpy(arr_std[i].name, ("son" + std::to_string(i + 1)).c_str());
        arr_std[i].age = 20 + rand() % 11;  // Random tuổi từ 20 đến 30
        arr_std[i].avg_score = static_cast<float>(rand() % 1001) / 100;  // Random điểm từ 0.00 đến 10.00
    }

    return arr_std;
}


student_t* add_student(int n, student_t* obj){
    // student_t* arr_std = (student_t*)malloc(n*sizeof(student_t));
    student_t* arr_std = new student_t[n+1];
    for (int i=0;i<n;i++){
        arr_std[i]=obj[i];
    }
        cout << "add nember: " << n + 1 << ":\n";
        cout << "ID = " << n <<endl;
        arr_std[n].ID = n;

        cout << "name: ";
        cin >> ws;
        cin.getline(arr_std[n].name, 20);
        cout << "age: ";
        cin >> arr_std[n].age;
        cout << "avg score: ";
        cin >> arr_std[n].avg_score;
        cin.ignore();  // Xóa bộ nhớ đệm trước khi dùng getline
    free(obj);
    return arr_std;
}

void print_students(int n, student_t* obj, int ID_width ,int name_width , int age_width, int score_width)
{
    cout << left << setw(ID_width) << "ID"
         << setw(name_width) << "Name" 
         << setw(age_width) << "age" 
         << setw(score_width) << "AVG score" 
         << endl;
    cout << string(name_width + age_width + score_width, '-') << endl;

    // In danh sách sinh viên
    for (int i = 0; i < n; i++) {
        cout << left << setw(ID_width) << obj[i].ID
             << setw(name_width) << obj[i].name 
             << setw(age_width) << obj[i].age 
             << setw(score_width) << obj[i].avg_score 
             << endl;
    }
}

int partition (student_t* obj,int low, int high){//copy a obj in d=left and right pivot
    if (obj == NULL)return 0;
    auto swap = [](student_t& obj1, student_t& obj2){
        student_t tmp = obj1;
        obj1 = obj2;
        obj2 = tmp;
    };
    int i = low - 1;// counter store index left arr
    for (int j=low; j<high;j++){
        if(obj[j].avg_score < obj[high].avg_score){
            i++;
            swap(obj[j],obj[i]);
        }
    }
    swap(obj[i+1],obj[high]);
    return (i+1);
}

void quickSort(student_t* obj,int low,int high){
    if (obj == NULL)return ;
    if(low<high){
        int pi = partition(obj,low,high);
        quickSort(obj,low,pi-1);
        quickSort(obj,pi+1,high);
    }
}
void sortByAvgScore (student_t* obj, int n){
    if (obj == NULL)return;
    quickSort(obj, 0, n-1); 
}

int binarySeach(int target, student_t* obj, int low,int high){
    if (obj == NULL) return 0;
    if (low <high){
        int mid = low + (high-low)/2;
        if (obj[mid].avg_score == target){
            return obj[mid].ID;
        }
        if (obj[mid].avg_score < target){
            low = mid + 1;
            return binarySeach(target, obj,low,high);
        }
        if (obj[mid].avg_score > target){
            high = mid -1;
            return binarySeach(target, obj,low,high);  
        }
    }
}
int SeachByAvgScore (int target, student_t *obj, int n){
    return binarySeach(target,obj,0,n-1);
}

int& editAge (student_t *obj, int id){
    return obj[id].age;
}

int& editAvgScore(student_t *obj, int id)
{
    return obj[id].avg_score;
}

int calAvgScore (student_t* obj, int id , int count, ...){
    if(count == 0 ) return 0;
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    obj[id].avg_score = total/count;
    return total/count;
}









