#ifndef INTMANAGMENT_H_
#define INTMANAGMENT_H_
typedef struct intManagment intManagment;
intManagment* creat_ptr_managment ();
void initArr (intManagment* obj,int size);
void printListArr (intManagment* arr);
int insertAtIndex (intManagment* arr,int index, int value);
int deleteAtIndex (intManagment* arr, int index);
void sortAscending (intManagment* arr);
void sortDescending (intManagment* arr);
int checkValue (intManagment* arr , int value);
void destroyIntManagment (intManagment* arr);
#endif