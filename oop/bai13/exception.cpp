#include "exception.h"

void validateBirthDay(const string& birthDay) {
    regex pattern(R"(\d{4}-\d{2}-\d{2})"); 
    if (!regex_match(birthDay, pattern)) {
        throw BirthDayException("Date of birth must be in YYYY-MM-DD format!");
    }
}

void validatePhone(const string& phone) {
    regex pattern(R"(\d{10})"); 
    if (!regex_match(phone, pattern)) {
        throw PhoneException("Phone number must be 10 digits!");
    }
}

void validateEmail(const string& email) {
    regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    if (!regex_match(email, pattern)) {
        throw EmailException("Invalid email!");
    }
}

void validateFullName(const string& fullName) {
    regex pattern(R"(^[a-zA-Z ]+$)");
    if (!regex_match(fullName, pattern)) {
        throw FullNameException("Full name can only contain letters and spaces!");
    }
}

void validateId(const int& id) {
    if(id < 0){
        throw IdException("ID can only contain digit!");;
    }
}