#include "list.h"
#include <stdio.h>

int main() {
    InitArray(); 

    AddElement(10);
    AddElement(5);
    AddElement(20);
    AddElement(15);

    Display();  

    Sort();
    Display();  

    int idx = Search(10);
    if (idx != -1)
        printf("Found 10 at index %d\n", idx);
    else
        printf("10 not found\n");

    DeleteElement(5);
    Display();  

    return 0;
}
