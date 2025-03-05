#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>
#include <utility>

#define PHONE_PREFIX "(090|098|091|031|035|038)"

void InvalidFullNameException (std::string& fullName);
void InvalidDOBException (std::string& doB);
void InvalidPhoneNumberException(std::string& phoneNumber);
void InvalidEntryYearException(int entryYear , int min = 2000, int max = 2025);
void InvalidEntryScoreException(float entryTestScore, float min = 0, float max=10);
void InvalidSemesterException(float semeScore, float min = 0, float max=10);
