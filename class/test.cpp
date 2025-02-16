#include "iostream"

using namespace std;
class Example {
    char a;   // 1 byte
    int b;    // 4 bytes
    double c; // 8 bytes
};

int main (){
    cout << "Size of Example: " << sizeof(Example) << " bytes" << endl;
}


