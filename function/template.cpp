#include <iostream>
using namespace std;

// Hàm template tìm số lớn nhất
template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(10, 20) << endl;      // int
    cout << myMax(3.14, 2.71) << endl;  // double
    cout << myMax('a', 'z') << endl;    // char
    return 0;
}
