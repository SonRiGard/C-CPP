#include <iostream>
using namespace std;

int (*funcPtr)(int, int);  // Định nghĩa con trỏ hàm

int main() {
    // Lambda function KHÔNG có capture list []
    funcPtr = [](int a, int b) -> int { return a + b; };

    cout << "Result: " << funcPtr(5, 10) << endl;  // Output: 15
    return 0;
}
