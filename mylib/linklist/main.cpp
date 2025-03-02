#include "LinkList.h"

int main() {
    LinkedList list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(5);
    list.pushFront(2);

    std::cout << "list = :\n";
    list.printList();

    std::cout << "size : " << list.getSize() << "\n";

    list.popFront();
    std::cout << "after pop first:\n";
    list.printList();

    list.popBack();
    std::cout << "pop back:\n";
    list.printList();

    list.clear();
    std::cout << "clear:\n";
    list.printList();

    return 0;
}
