#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "input.h"

struct array{
    int *address; 
    int capacity;
    int size;
};

array* creat_ptr_managment (){
    array* tmpPtr = (array*)malloc(sizeof(array));
    tmpPtr-> address =NULL;
    tmpPtr-> size = 0;
    return tmpPtr;
}

void destroyIntManagment (array* arr){
    free(arr->address);
}

void InitArray(array* arr, int size){
    if (size <=0){
        printf(" Error: size of array <= 0\n");
        return;
    };
    if(arr->size == 0){//old size of array == 0 don't need free because arr->data = null
        arr->size = size;
        arr->address = (int*)malloc(arr->size * sizeof(int));
        if (arr->address == NULL){
            printf("Memory reallocation failed");
            return;
        };
        for (int i=0; i<arr->size ; i++){
            printf("Enter value off array index = [ %d] ", i);
            arr->address[i] = getInt();
            printf("\n-----------------------------\n");
        }
        return;
    }else{
        arr->size = size;
        arr->address = (int*)realloc(arr->address,arr->size * sizeof(int));
        for (int i=0; i<arr->size ; i++){
            printf("Enter value off array index = [ %d] ", i);
            arr->address[i] = getInt();
            printf("\n-----------------------------\n");
        }
    }
};

void printListArr (array* arr){
    if(arr == NULL) {
        printf("ERROR: print null poiter\n");
        return;
    } ;
    printf("arr = [index:value] ");
    for(int i=0; i<arr->size; i++){
        printf(" [%d]:[%d] ",i,arr->address[i]);
    }
    printf("\n");
};

int AddElement(array* arr,int index, int value){
    if(arr == NULL) {
        printf("ERROR: insert at array null poiter\n");
        return 0;
    } ;

    if(index<0 || index > arr->size){
        printf("index not avaiable!\n");
        return 0;
    };

    arr->size += 1;
    if (arr->address != NULL){
        arr->address = (int*)realloc(arr->address,arr->size*sizeof(int));
        if(arr -> address == NULL){
            printf("Memory reallocation failed");
            return 0;
        }
    }else if (arr->address == NULL){
        arr-> address = (int*)malloc(arr->size*sizeof(int));
    }


    for (int i=arr->size-1;i>index;i--){
        arr->address[i]=arr->address[i-1];
    }
    arr->address[index] = value;
    return 1;
};

int DelElement (array* arr, int index){
    if(arr == NULL) {
        printf("ERROR: deletedelete at array null poiter\n");
        return 0;
    } ;
    if(index<0 || index >= arr->size){
        printf("index not avaiable!\n");
        return 0;
    }
   
    if(arr->size == 1){
        arr->size == 0;
        free(arr->address);
        return 1;
    }
    
    for (int i=index;i<arr->size-1;i++){
        arr->address[i]=arr->address[i+1];
    }

    arr->size -= 1;
    arr->address = (int*)realloc(arr->address,arr->size*sizeof(int));
    return 1;
};

// Hàm Partition: Chia mảng thành 2 phần, tùy theo hướng sắp xếp (tăng dần hoặc giảm dần)
int partition(int arr[], int low, int high, int ascending) {
    int pivot = arr[high];  // Chọn phần tử cuối cùng làm pivot
    int i = (low - 1);  // Chỉ số của phần tử nhỏ hơn pivot

    // Nếu sắp xếp tăng dần
    if (ascending) {
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {  // Nếu phần tử hiện tại nhỏ hơn pivot
                i++;
                // Hoán đổi arr[i] và arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    } else {  // Nếu sắp xếp giảm dần
        for (int j = low; j < high; j++) {
            if (arr[j] > pivot) {  // Nếu phần tử hiện tại lớn hơn pivot
                i++;
                // Hoán đổi arr[i] và arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Hoán đổi arr[i + 1] và arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  // Trả về chỉ số của pivot sau khi phân tách
}

void quickSort(int* arr, int low, int high, int ascending) {
    if(arr == NULL){
        printf("ERROR: can't sort null array");
    }
    if (low < high) {
        // Phân tách mảng và lấy vị trí pivot
        int pi = partition(arr, low, high, ascending);

        // Đệ quy sắp xếp hai nửa mảng
        quickSort(arr, low, pi - 1, ascending);  // Sắp xếp phần trái
        quickSort(arr, pi + 1, high, ascending); // Sắp xếp phần phải
    }
}

void Sort (array* arr, int i){// sort inc - 1; des -0
    if (i== 0 || i==1){
        quickSort(arr->address,0,arr->size - 1,i);
    }
};

int Search(array* arr , int value){
    for(int i=0;i<arr->size;i++){
        if(arr->address[i]==value) return 1; 
    }
    return 0;
};
