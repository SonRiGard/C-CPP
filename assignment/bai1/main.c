#include <stdio.h>
#include "intManagment.h"
#include "input.h"

int main(){
    int exit = 0;
    intManagment* ObjIntManagment = creat_ptr_managment();
    while (!exit) {
        printf("Array Management Program\n");
        printf("User Guide:\n");
        printf(" - Enter 'c' to create a new array\n");
        printf(" - Enter 'p' to print the array\n");
        printf(" - Enter 'i' to insert an element into the array\n");
        printf(" - Enter 'd' to delete an element from the array\n");
        printf(" - Enter 's' to sort in ascending order\n");
        printf(" - Enter 'x' to sort in descending order\n");
        printf(" - Enter 't' to search for a number in the array\n");
        printf(" - Enter 'e' to exit the program\n");
        printf(" - Enter your choice: ");
        char choice = getChar();
        int num;
            switch (choice) {
                case 'c':
                    printf("\nEnter the number of elements in the array: ");
                    num = getInt();
                    initArr(ObjIntManagment,num);
                    break;
                case 'p':
                    printListArr(ObjIntManagment);
                    break;
                case 'i': {
                    printf("Enter the index to insert: ");
                    int index = getInt();
                    printf("\n");

                    printf("Enter the value to insert: ");
                    int value = getInt();
                    printf("\n");

                    if (insertAtIndex(ObjIntManagment,index,value )) {
                        printf("Insertion successful!\n");
                    }
                    break;
                }
                case 'd': {
                    printf("Enter the index to delete: ");
                    int index = getInt();
                    if (deleteAtIndex(ObjIntManagment, index)) {
                        printf("Deletion successful!\n");
                    }
                    break;
                }
                case 's':
                    sortAscending(ObjIntManagment);
                    printf("Array sorted in ascending order.\n");
                    break;
                case 'x':
                    sortDescending(ObjIntManagment);
                    printf("Array sorted in descending order.\n");
                    break;
                case 't': {
                    printf("Enter the number to search: ");
                    int x = getInt();
                    printf("\n");
                    if (checkValue(ObjIntManagment, x)) {
                        printf("Number %d is in the array.\n", x);
                    } else {
                        printf("Number %d is not in the array.\n", x);
                    }
                    break;
                }
                case 'e':
                    printf("Exiting the program.\n");
                    exit = 1;
                    return 0;
                default:
                    printf("Invalid choice! Please try again.\n");
                }
        }
        destroyIntManagment(ObjIntManagment);
        return 0;
}
