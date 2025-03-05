#include "exception.h"


void InvalidFullNameException (std::string& fullName){
    std::regex fullNamePatten(R"([a-zA-Z ]{1,50})");
    if(!regex_match(fullName,fullNamePatten)){
        throw std::runtime_error("Fullname only contain lettes and space");
    }
};

void InvalidDOBException (std::string& doB){
    std::regex doBPatten(R"(^\d{2}-\d{2}-\d{4}$)");
    if(!regex_match(doB,doBPatten)){
        throw std::runtime_error("Invalid Date format (YYYY-MM-DD)");
    }
};

void InvalidPhoneNumberException(std::string& phoneNumber){
    std::regex phonePatten(R"((090|098|091|031|035|038)\d{7})");
    if(!regex_match(phoneNumber,phonePatten)){
        throw std::runtime_error("Invalid Phone Number format! ");
    }
};