#include<iostream>
using namespace std;
class Animal {
public:
    virtual void  makeSound() {  // Hàm ảo có thân hàm
        std::cout << "Animal sound!" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound()  {  // Override lại hàm ảo
        std::cout << "Woof! Woof!" << std::endl;
    }
};

int main() {
    Animal* a = new Dog();
    a->makeSound();  // Gọi hàm của lớp Dog nhờ cơ chế đa hình
    delete a;
}