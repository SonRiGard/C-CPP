#include <stdio.h>
#include <stdlib.h>
#include "opaque.h"
#include <stdlib.h>

int add(int a){
    return a;
}
// Định nghĩa struct (Ẩn trong file .c)
struct MyStruct {
    char hj[50];
    int data;
};

// Hàm tạo struct
MyStruct* create_struct(int value) {
    MyStruct* obj = (MyStruct*)malloc(sizeof(MyStruct));
    if (obj) {
        obj->data = value;
    }
    return obj;
}

// Hàm lấy giá trị từ struct
int get_value(MyStruct* obj) {
    return obj ? obj->data : 0;
}

// Hàm giải phóng struct
void destroy_struct(MyStruct* obj) {
    free(obj);
}

void print_size(MyStruct* obj) {
    printf("size of struct %d",sizeof(MyStruct));
}

