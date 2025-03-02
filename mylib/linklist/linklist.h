#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Lớp danh sách liên kết
class LinkedList {
private:
    Node* head;
    Node* tail;
    size_t size;
    
public:
    LinkedList();          // Constructor
    ~LinkedList();         // Destructor

    void pushFront(int value);  // Thêm vào đầu danh sách
    void pushBack(int value);   // Thêm vào cuối danh sách
    void popFront();            // Xóa đầu danh sách
    void popBack();             // Xóa cuối danh sách
    bool isEmpty() const;       // Kiểm tra rỗng
    size_t getSize() const;     // Lấy kích thước danh sách
    void printList() const;     // In danh sách
    void clear();               // Xóa toàn bộ danh sách
};

#endif // LINKLIST_H
