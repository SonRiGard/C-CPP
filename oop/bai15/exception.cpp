#include "exception.hpp"


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
    std::regex phonePatten(std::string(PHONE_PREFIX) + R"(\d{7})");
    if(!regex_match(phoneNumber,phonePatten)){
        throw std::runtime_error("Invalid Phone Number format! ");
    }
};

void InvalidEntryScoreException(float entryTestScore, float min, float max){
    if(entryTestScore < min || entryTestScore > max){
        throw std::out_of_range("Entry test score must be in range");
    }
};

void InvalidEntryYearException(int entryYear , int min , int max){
    if(entryYear < min || entryYear > max){
        throw std::runtime_error ("Entry year must be in range");
    }
};

void InvalidSemesterException(float semeScore, float min, float max)
{
    if(semeScore < min || semeScore > max){
        throw std::out_of_range("Semester score must be in range");
    }
};