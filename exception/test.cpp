#include <iostream>
#include <string>
using namespace std;

int simpleHash(string key, int tableSize) {
    int hashValue = 0;
    for (char c : key)
        hashValue += c;
    return hashValue % tableSize;
}

int main() {
    string key = "hello";
    int tableSize = 10;
    
    cout << "Hash index for '" << key << "': " << simpleHash(key, tableSize) << endl;
    return 0;
}
