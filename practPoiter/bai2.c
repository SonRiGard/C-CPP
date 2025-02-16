#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  {
    char name[20];
    int age;
    float avg_score;
}SinhVien ;

typedef SinhVien* ptrSinhVien;
int count = 0;
int addsv(SinhVien* ptrsv,int count){
    ptrsv->age = 24;
    strcpy((*ptrsv).name,"son");
    ptrsv->avg_score = 3.4;
}

int main (){
//- Khai báo và sử dụng con trỏ để trỏ đến một biến SinhVien
    ptrSinhVien son;
    son->age = 24;
    strcpy((*son).name,"son");
    son->avg_score = 3.4;
    prinf("done 1 phase");

//Sử dụng con trỏ mảng:
    ptrSinhVien ptrdanhsach = (ptrSinhVien)alloc(count*sizeof(SinhVien));

}
