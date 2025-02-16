#ifndef OPAQUE_H
#define OPAQUE_H

// Chỉ khai báo con trỏ mà không tiết lộ nội dung struct
typedef struct MyStruct MyStruct;

// Hàm API để làm việc với MyStruct
MyStruct* create_struct(int value);
int get_value(MyStruct* obj);
void destroy_struct(MyStruct* obj);
void print_size();
#endif
