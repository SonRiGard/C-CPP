#include "iostream"
#include "students.h"
using namespace std;

int main(){
    int n =10;
    // use oqaque poiterpoiter
    student_t* ptr_class = create_students_auto(n); 
    
    ptr_class = add_student(n,ptr_class);
    print_students(n+1,ptr_class,2,20,10,15);//default parameters width of table colums
    sortByAvgScore(ptr_class,n+1);//quicksort and recusion
    cout << "after sort" << endl;
    print_students(n+1,ptr_class);
    int target;
    cout << "Seach student have AVG_score =  " ; cin >> target ;cout<<endl;
    cout << SeachByAvgScore(target,ptr_class,n+1)<< endl;//print one student in list have avg_score = target
    
    cout << "calculate AVG score"<< endl;
    cout << "new value of obj[1] = " << calAvgScore(ptr_class,1,3,4,2,3)<< endl;
}