#include <iostream>
using namespace std;

int main() {
    int x = 10;

    auto increaseX = [x]() mutable {
        x += 5;  // Allowed because of 'mutable'
        cout << "Inside Lambda: " << x << endl;
    };

    increaseX();
    cout << "Outside Lambda: " << x << endl; // x is NOT modified in main()
    return 0;
}
