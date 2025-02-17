#include <stdio.h>
#include "opaque.h"

int main() {
    // MyStruct abj;
    MyStruct* obj ;
    obj  = create_struct(42);
    
    if (obj) {
        printf("Gia tri trong Struct: %d\n", get_value(obj));
        print_size();
        printf("size of struct %d",sizeof(&obj));
        destroy_struct(obj);
    }
    return 0;
}
