#include <iostream>
using namespace std;

class MoveExample {
public:
    int* data;

    MoveExample(int val) {
        data = new int(val);
    }

    // Move Constructor
    MoveExample(MoveExample&& obj) noexcept {
        data = obj.data;  // Transfer ownership
        obj.data = nullptr;  // Prevent dangling pointer
    }

    void show() { cout << "Value: " << *data << endl; }

    ~MoveExample() { delete data; }
};

int main() {
    MoveExample obj1(20);
    MoveExample obj2 = move(obj1);  // Move Constructor called

    obj2.show();
    return 0;
}