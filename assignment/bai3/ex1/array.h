#ifndef ARRAY_H_
#define ARRAY_H_
typedef struct array array;
array* creat_ptr_managment ();
void InitArray(array* arr, int size);
int AddElement(array* arr,int index, int value);
int DelElement (array* arr, int index);
void Sort (array* arr, int i);// sort inc - 1; des -0
int Search(array* arr , int value);
void printListArr (array* arr);
#endif