#include <iostream>
#include <string>
#include <vector>


class Student {
protected:
    std::string fullName;
    std::string doB;
    std::string sex;
    std::string phoneNumber;
    std::string universityName;
    std::string gradeLevel;

public:
    Student(const std::string& fullName, const std::string& doB, const std::string& sex,
            const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel)
        : fullName(fullName), doB(doB), sex(sex), phoneNumber(phoneNumber), universityName(universityName), gradeLevel(gradeLevel) {
        validate();
    }

    virtual void ShowMyInfor() const {
        std::cout << "Full Name: " << fullName << "\n"
                  << "Date of Birth: " << doB << "\n"
                  << "Sex: " << sex << "\n"
                  << "Phone Number: " << phoneNumber << "\n"
                  << "University Name: " << universityName << "\n"
                  << "Grade Level: " << gradeLevel << "\n";
    }

    virtual ~Student() = default;

protected:
    void validate() {
        if (fullName.length() < 10 || fullName.length() > 50) {
            throw InvalidFullNameException();
        }

        std::regex dobPattern(R"(\d{2}/\d{2}/\d{4})");
        if (!std::regex_match(doB, dobPattern)) {
            throw InvalidDOBException();
        }

        std::regex phonePattern(R"(^(090|098|091|031|035|038)\d{7}$)");
        if (!std::regex_match(phoneNumber, phonePattern)) {
            throw InvalidPhoneNumberException();
        }
    }
};

class GoodStudent : public Student {
private:
    double gpa;
    std::string bestRewardName;

public:
    GoodStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                double gpa, const std::string& bestRewardName)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}

    void ShowMyInfor() const override {
        Student::ShowMyInfor();
        std::cout << "GPA: " << gpa << "\n"
                  << "Best Reward Name: " << bestRewardName << "\n";
    }
};

class NormalStudent : public Student {
private:
    int englishScore;
    double entryTestScore;

public:
    NormalStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                  const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                  int englishScore, double entryTestScore)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore) {}

    void ShowMyInfor() const override {
        Student::ShowMyInfor();
        std::cout << "English Score: " << englishScore << "\n"
                  << "Entry Test Score: " << entryTestScore << "\n";
    }
};

int main() {
    try {
        std::vector<Student*> students;
        students.push_back(new GoodStudent("Nguyen Van A", "01/01/1995", "Male", "0901234567", "FPT University", "Good", 8.5, "Scholarship A"));