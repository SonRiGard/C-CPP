#include "employee.h"
#include <iomanip>
#include "input.h"
#include "exception.h"

#define DEBUGMODE
void Employee::showInfo(){
    std::cout <<"----------------------------------------------------------------------\n";
    std::cout <<std::left<<std::setw(3)<< ID<<":"<< FullName<<" "<<BirthDay<<" Phone: "<<Phone<<" - Email: "<< Email << std::endl;
}

void Employee::descreaseEmployeeCount(){
    Employee_count--;
}

unsigned int Employee::getEmployee_count(){
    return Employee_count;
}

unsigned int Employee::getId(){
    return this->ID;
};

std::string Employee::getEmployee_Type(){
    return Employee_type;
};

void Employee::showCertificate(){
    std::cout <<"Certificate: ";
    if(!ptrCer.empty()){
        std::cout << std::endl;
        for(auto cer : ptrCer){
            cer->ShowCertificate();
        }
    }else{
        std::cout << "Certificate is empty\n";
    }
}

Employee::~Employee(){
    for(auto pte:ptrCer){
        #ifdef DEBUGMODE
        std::cout << "destructor employee called clear data Employee and they certificate\n";
        #endif
        delete pte;
    }
    Employee_count--; 
};

void Employee::setCertificate(){
    bool endCer = false;
    std::cout << "Enter certificates information:\n";
    std::string chose="";
    do{
        std::cout << "Employee has more certificate? [Y/N]";
        do{
            std::getline(std::cin,chose);
        }while(!(chose == "Y" || chose == "N"));

        if(chose == "Y"){
            unsigned int tmpCertificatedID;
            std::string tmpCertificateName,tmpCertificateRank,tmpCertificatedDate;
            std::cout << "Enter Certificated ID: ";
            std::cin >> tmpCertificatedID;
            std::cin.ignore();

            std::cout << "Enter Certificated Name: ";
            std::getline(std::cin,tmpCertificateName);

            std::cout << "Enter Certificated Rank: ";
            std::getline(std::cin,tmpCertificateRank);

            std::cout << "Enter Certificated Date (YYYY-MM-DD): ";
            std::getline(std::cin,tmpCertificatedDate);

            ptrCer.push_back(new Certificate(tmpCertificatedID,tmpCertificateName,tmpCertificateRank,tmpCertificatedDate));
        }else{
            endCer =true; 
        }
    }while(!endCer);
};

void Employee::editInfor(){
    std::cout <<"----------------------------------------------------------------------\n";
    std::string tmpString;
    bool inforValid = false;

    std::cout << "Editing employee ID = "<<this->ID;

    while(!inforValid){
        try {
            std::cout << "Enter Full Name: ";
            std::getline(std::cin, tmpString);
            validateFullName(tmpString);
            this->FullName = tmpString;

            std::cout << "Enter Birthday (YYYY-MM-DD): ";
            std::cin >> tmpString;
            validateBirthDay(tmpString);
            this->BirthDay = tmpString;

            std::cout << "Enter Phone number(10 digits): ";
            std::cin >> tmpString;
            validatePhone(tmpString);
            this->Phone = tmpString;

            std::cout << "Enter Email: ";
            std::cin >> tmpString;
            validateEmail(tmpString);
            this->Email = tmpString;
            #ifdef BEBUGMODE
            std::cout << "\nValidate Information!\n";
            std::cout << "Name: " << fullName << "\nBirthday: " << birthDay << "\nPhoneNumber: " << phone << "\nEmail: " << email << endl;
            #endif
            inforValid = true;
        } 
        catch (const exception& e) {
            std::cout << "\nError: " << e.what() << endl;
        }
    } 

}



