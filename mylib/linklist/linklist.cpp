#include "LinkList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destructor: Giải phóng bộ nhớ khi danh sách bị hủy
LinkedList::~LinkedList() {
    clear();
}

// Thêm phần tử vào đầu danh sách
void LinkedList::pushFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = newNode;
    }

    size++;
}

// Thêm phần tử vào cuối danh sách
void LinkedList::pushBack(int value) {
    Node* newNode = new Node(value);
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    size++;
}

// Xóa phần tử đầu danh sách
void LinkedList::popFront() {
    if (!head) return;

    Node* temp = head;
    head = head->next;
    if (!head) {
        tail = nullptr;
    }

    delete temp;
    size--;
}

// Xóa phần tử cuối danh sách
void LinkedList::popBack() {
    if (!head) return;

    if (head == tail) {  // Trường hợp danh sách chỉ có 1 phần tử
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        temp->next = nullptr;
    }

    size--;
}

// Kiểm tra danh sách có rỗng không
bool LinkedList::isEmpty() const {
    return size == 0;
}

// Lấy kích thước danh sách
size_t LinkedList::getSize() const {
    return size;
}

// In danh sách
void LinkedList::printList() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Xóa toàn bộ danh sách
void LinkedList::clear() {
    while (head) {
        popFront();
    }
}
