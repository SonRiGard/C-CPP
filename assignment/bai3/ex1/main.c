#include <stdio.h>
#include "array.h"
#include "input.h"
int main (){
    array* arr = creat_ptr_managment();
    printf("------------------------------------------------\n");
    printf("\nEnter the number of elements in the array: ");
    int num = getInt();
    //--------INIT--------
    printf("------------------------------------------------\n");
    InitArray(arr,num);
    printListArr(arr); 
    //---AddElement()-----
    printf("------------------------------------------------\n");
    printf("Enter the index to insert: ");
    int index = getInt();
    printf("\n");
    
    printf("Enter the value to insert: ");
    int value = getInt();
    printf("\n");

    if (AddElement(arr,index,value )) {
        printf("Insertion successful!\n");
    }
    printListArr(arr); 
    //---DELElement()-----
    printf("------------------------------------------------\n");
    printf("Enter the index to delete: ");
    index = getInt();
    if (DelElement(arr, index)) {
        printf("Deletion successful!\n");
    }
    printListArr(arr); 
    //------Sort()--------
    printf("------------------------------------------------\n");
    Sort(arr,1);
    printf("Array sorted in ascending order.\n");
    printListArr(arr); 
    Sort(arr,0);
    printf("Array sorted in descending order.\n");
    printListArr(arr); 
    //------Seach()--------
    printf("------------------------------------------------\n");
    printf("Enter the number to search: ");
    int x = getInt();
    printf("\n");
    if (Search(arr, x)) {
        printf("Number %d is in the array.\n", x);
    } else {
        printf("Number %d is not in the array.\n", x);
    }
}

