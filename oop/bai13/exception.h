#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <iostream>
#include <stdexcept>
#include <regex>

using namespace std;

class BirthDayException : public runtime_error {
public:
    BirthDayException(const string& msg) : runtime_error("BirthDayException: " + msg) {}
};

class PhoneException : public runtime_error {
public:
    PhoneException(const string& msg) : runtime_error("PhoneException: " + msg) {}
};

class EmailException : public runtime_error {
public:
    EmailException(const string& msg) : runtime_error("EmailException: " + msg) {}
};

class FullNameException : public runtime_error {
public:
    FullNameException(const string& msg) : runtime_error("FullNameException: " + msg) {}
};

class IdException : public runtime_error {
    public:
    IdException(const string& msg) : runtime_error("IdException: " + msg) {}
    };

void validateBirthDay(const string& birthDay) ;

void validatePhone(const string& phone);

void validateEmail(const string& email);

void validateFullName(const string& fullName);

void validateId(const int& id);

#endif