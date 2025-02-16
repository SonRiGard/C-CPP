// #include<iostream>
// using namespace std;

// int main(){
//     int a = 11, b =2;
//     auto lambda = [&](){
//         a = 4;
//         b = 3;
//         cout<<"a= "<<a<<endl;
//         cout<<"b= "<<b<<endl;
//     };

//     auto lambda2 = [=](){cout<<"a+b= "<<a+b<<endl;};
//     lambda();
//     lambda2();
//     return 0;
// }

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}