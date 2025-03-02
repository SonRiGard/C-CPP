#ifndef MAP_H
#define MAP_H

#include <iostream>

template <typename K, typename V>
class Map {
private:
    // Định nghĩa node trong BST
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Hàm đệ quy để chèn phần tử
    Node* insert(Node* node, K key, V value) {
        if (node == nullptr) return new Node(key, value);
        if (key < node->key) node->left = insert(node->left, key, value);
        else if (key > node->key) node->right = insert(node->right, key, value);
        else node->value = value; // Nếu key đã tồn tại, cập nhật giá trị
        return node;
    }

    // Hàm tìm kiếm phần tử theo key
    Node* find(Node* node, K key) const {
        if (node == nullptr || node->key == key) return node;
        if (key < node->key) return find(node->left, key);
        return find(node->right, key);
    }

    // Tìm phần tử nhỏ nhất trong cây con phải (hỗ trợ xóa)
    Node* minValueNode(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    // Xóa node theo key
    Node* erase(Node* node, K key) {
        if (node == nullptr) return node;
        
        if (key < node->key) node->left = erase(node->left, key);
        else if (key > node->key) node->right = erase(node->right, key);
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = erase(node->right, temp->key);
        }
        return node;
    }

    // Duyệt cây theo thứ tự (in-order)
    void inorder(Node* node) const {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->key << ": " << node->value << std::endl;
            inorder(node->right);
        }
    }

    // Giải phóng bộ nhớ
    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    // Constructor
    Map() : root(nullptr) {}

    // Destructor
    ~Map() {
        clear(root);
    }

    // Thêm hoặc cập nhật phần tử
    void insert(K key, V value) {
        root = insert(root, key, value);
    }

    // Xóa phần tử theo key
    void erase(K key) {
        root = erase(root, key);
    }

    // Lấy giá trị theo key
    V get(K key) const {
        Node* node = find(root, key);
        if (node != nullptr) return node->value;
        throw std::runtime_error("Key not found");
    }

    // Kiểm tra xem key có tồn tại không
    bool contains(K key) const {
        return find(root, key) != nullptr;
    }

    // Hiển thị toàn bộ cây theo thứ tự
    void print() const {
        inorder(root);
    }
};

#endif
