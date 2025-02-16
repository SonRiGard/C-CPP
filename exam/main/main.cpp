#include<iostream>
using namespace std;

int main(){
    int a = 11, b =2;
    auto lambda = [&](){
        a = 4;
        b = 3;
        cout<<"a= "<<a<<endl;
        cout<<"b= "<<b<<endl;
    };

    auto lambda2 = [=](){
        cout<<"a+b= "<<a+b<<endl;
    };
    lambda();
    lambda2();
    return 0;
}