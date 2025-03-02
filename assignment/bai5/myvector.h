#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class vector {
    private: 
        T* data;
        unsigned int size;
        unsigned int capacity;

            void resize(unsigned int newcapacity) {
                T* dataTemp = new T[newcapacity]; 
                for (unsigned int i = 0; i < size && i < newcapacity; i++) {
                    dataTemp[i] = data[i];
                }
                delete[] data;  // Giải phóng bộ nhớ cũ
                data = dataTemp;  // Cập nhật con trỏ
                capacity = newcapacity;
            }
            
    
    public:
        vector(): size(0), capacity(1){
            data = new T[capacity];
        };

        vector(int n, T value): size(n), capacity(n){
            data = new T[capacity];
            for (int i =0; i<size;i++){
                data[i] = value;
            }
        }

        ~vector(){
            delete[] data;
            data = nullptr;
        }

        unsigned int getSize (){
            return size;
        }

        unsigned int getCapacity (){
            return capacity;
        }

        void push_back(T value){
            if (size >= capacity) {
                resize(capacity * 2);
            }
            if (data) {  // Kiểm tra con trỏ hợp lệ trước khi truy cập
                data[size] = value;
                size++;
            } else {
                std::cerr << "Lỗi: Bộ nhớ data bị NULL!" << std::endl;
            }
        }

        void pop_back() {
            if (size > 0) {
                size--;
            }
        }

        void insert(unsigned int index, const T& value) {
            if (index > size) {
                cout << "insert index error";
                return;
            };
            if (size == capacity) {
                capacity *= 2;
                resize(capacity);
            }
            for (int i = size; i > index; i--) {
                data[i] = data[i - 1];
            }
            data[index] = value;
            size++;
        }
            // Xóa phần tử tại vị trí index
        void erase(size_t index) {
            if (index >= size) return;
            for (size_t i = index; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
        }

        void clear() {
            size = 0;
        }

        T& operator[](size_t index) {
            return data[index];
        }

        T& front() {
            return data[0];
        }

        T& back() {
            return data[size - 1];
        }

        void print() const {
            for (int i = 0; i < size; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }

        T getValueAtIndex(int i){
            return data[i];
        }

        T* getAddAtIndex(int i){
            return data+i;
        }
        bool isEmpty (){
            return size == 0;
        }

        T* begin (){
            return &data[0];
        }
        
        T* end (){
            return &data[size];
        } 

        void shrink_to_fit() {
            if (size < capacity) {
                T* newData = new T[size];
                for (unsigned int i = 0; i < size; i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
                capacity = size;
            }
        }
};

#endif