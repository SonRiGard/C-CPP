#include <iostream>
#include <string>
#include <utility>  // std::move
#include <vector>

class Employee {
protected:
    unsigned int ID;
    std::string FullName;
    std::string BirthDay;
    std::string Phone;
    std::string Email;
    std::string Employee_type;

public:
    // Constructor thông thường (copy)
    Employee(unsigned int ID, const std::string& FullName, const std::string& BirthDay,
             const std::string& Phone, const std::string& Email, const std::string& Employee_type)
        : ID(ID), FullName(FullName), BirthDay(BirthDay), Phone(Phone), Email(Email), Employee_type(Employee_type) {
        std::cout << "Employee (copy) created: " << FullName << std::endl;
    }

    // Move constructor (tối ưu hiệu suất)
    Employee(unsigned int ID, std::string&& FullName, std::string&& BirthDay,
             std::string&& Phone, std::string&& Email, std::string&& Employee_type)
        : ID(ID), FullName(std::move(FullName)), BirthDay(std::move(BirthDay)),
          Phone(std::move(Phone)), Email(std::move(Email)), Employee_type(std::move(Employee_type)) {
        std::cout << "Employee (moved) created: " << this->FullName << std::endl;
    }

    virtual ~Employee() {
        std::cout << "Employee destroyed: " << FullName << std::endl;
    }

    virtual void showMe() = 0;
};

class Experience : public Employee {
private:
    int ExpInYear;
    std::string ProSkill;

public:
    // Constructor thông thường
    Experience(unsigned int ID, const std::string& FullName, const std::string& BirthDay,
               const std::string& Phone, const std::string& Email, const std::string& Employee_type,
               int ExpInYear, const std::string& ProSkill)
        : Employee(ID, FullName, BirthDay, Phone, Email, Employee_type), ExpInYear(ExpInYear), ProSkill(ProSkill) {
        std::cout << "Experience (copy) created: " << FullName << std::endl;
    }

    // Move constructor
    Experience(unsigned int ID, std::string&& FullName, std::string&& BirthDay,
               std::string&& Phone, std::string&& Email, std::string&& Employee_type,
               int ExpInYear, std::string&& ProSkill)
        : Employee(ID, std::move(FullName), std::move(BirthDay), std::move(Phone),
                   std::move(Email), std::move(Employee_type)),
          ExpInYear(ExpInYear), ProSkill(std::move(ProSkill)) {
        std::cout << "Experience (moved) created: " << this->FullName << std::endl;
    }

    void showMe() override {
        std::cout << "Experience Employee: " << FullName << ", " << ProSkill << " (" << ExpInYear << " years)" << std::endl;
    }
};

int main() {
    std::cout << "=== Creating Employee with Copy Constructor ===\n";
    Experience e1(1, "John Doe", "1990-01-01", "0123456789", "john@example.com", "Engineer", 5, "C++");

    std::cout << "\n=== Creating Employee with Move Constructor ===\n";
    std::string tmpName = "Alice Smith";
    std::string tmpBirthDay = "1985-06-15";
    std::string tmpPhone = "0987654321";
    std::string tmpEmail = "alice@example.com";
    std::string tmpType = "Manager";
    std::string tmpProSkill = "Python";

    Experience e2(2, std::move(tmpName), std::move(tmpBirthDay), std::move(tmpPhone),
                  std::move(tmpEmail), std::move(tmpType), 10, std::move(tmpProSkill));

    std::cout << "\n=== Calling showMe() ===\n";
    e1.showMe();
    e2.showMe();

    return 0;
}
