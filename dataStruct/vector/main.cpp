#include <iostream>
#include "myvector.h"

using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout<< v.getSize()<<endl;

    std::cout << "Vector ban đầu: ";
    v.print();

    v.insert(1, 10);
    std::cout << "Sau khi chèn 10 vào vị trí 1: ";
    v.print();

    v.erase(2);
    std::cout << "Sau khi xóa phần tử vị trí 2: ";
    v.print();

    std::cout << "Kích thước hiện tại: " << v.getSize() << "\n";
    std::cout << "Dung lượng hiện tại: " << v.getCapacity() << "\n";

    for (int* it = v.begin(); it != nullptr && it != v.begin() + v.getSize(); ++it) {
        std::cout << *it << " ";
    }
    
    v.clear();
    std::cout << "Vector sau khi xóa toàn bộ: ";
    v.print();


    return 0;
}
