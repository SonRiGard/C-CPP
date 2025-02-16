#include <iostream>
using namespace std;

class Shallow {
public:
    int* data;

    // Constructor
    Shallow(int val) {
        data = new int(val);
    }

    // Copy Constructor (Shallow Copy)
    Shallow(const Shallow& obj) {
        data = obj.data;  // Only copies the pointer, NOT the actual value
    }

    void show() { cout << "Value: " << *data << endl; }

    ~Shallow() { delete data; }
};

Shallow abc(){
    
    Shallow obj1(10);
    static Shallow obj2 = obj1;  // Shallow copy
    
    obj1.show();
    obj2.show();
    return obj1;
}
int main() {
    Shallow obj3 = abc();
    obj3.show(); 
    cout << "abc" << endl;
    return 0;  // Double free error occurs (obj1 and obj2 delete same memory)
}