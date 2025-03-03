#include "managementEmployee.h"
#include "exception.h"
#include "input.h"
#include <string>

unsigned int Employee::Employee_count =0;

managementEmployee::managementEmployee(){

}

managementEmployee::~managementEmployee(){
    for(auto ptr:ptrEmployee){
        delete ptr;
    } 
};

void managementEmployee::addNewEmployee(){
    std::cout <<"----------------------------------------------------------------------\n";
    std::string tmpfullName, tmpbirthDay, tmpphone, tmpemail;
    unsigned int tmpid,tmpemtype;
    bool inforValid = false;


    std::cout << "Enter ID: ";
    tmpid = getUint16();
    std::cin.ignore();

    if(checkEmptyIdEmployee(tmpid)){//check if have id in current líst -> editedit

        editEmployeeById(tmpid);
        return;
    }
    while(!inforValid){
        try {
            std::cout << "Enter Full Name: ";
            std::getline(std::cin, tmpfullName);
            validateFullName(tmpfullName);

            std::cout << "Enter Birthday (YYYY-MM-DD): ";
            std::cin >> tmpbirthDay;
            validateBirthDay(tmpbirthDay);

            std::cout << "Enter Phone number(10 digits): ";
            std::cin >> tmpphone;
            validatePhone(tmpphone);

            std::cout << "Enter Email: ";
            std::cin >> tmpemail;
            validateEmail(tmpemail);
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

    std::cout<<"Enter Employee Type 0: Experience, 1: Fresher , 2: Intern\n";
    do{
        std::cout << "Enter Type: ";
        std::cin >> tmpemtype;
    }while(!(tmpemtype == 0 || tmpemtype == 1 || tmpemtype == 2));

    if(tmpemtype == 0){//extended data for experiences
        int tmpexpInYear ;std::string tmpemtypestr = "Experience";
        std::string tmpProskill;

        std::cout << "Enter Expirence in years: ";
        tmpexpInYear = getUint8();
        std::cin.ignore();

        std::cout << "Enter Professional Skill: ";
        std::getline(std::cin,tmpProskill);
        ptrEmployee.push_back(new Experience(tmpid,std::move(tmpfullName),std::move(tmpbirthDay),std::move(tmpphone),
        std::move(tmpemail),std::move(tmpemtypestr),tmpexpInYear,std::move(tmpProskill)));
    }else if(tmpemtype == 1){//extended data for Freshers
        std::string tmpemtypestr = "Fresher";
        std::string tmpGraduation_date,tmpGraduation_rank,Education;
        std::cout << "Enter Graduation Date: ";
        std::cin.ignore();
        std::getline(std::cin,tmpGraduation_date);

        std::cout << "Enter Graduation Rank: ";
        std::getline(std::cin,tmpGraduation_rank);

        std::cout << "Enter Education: ";
        std::getline(std::cin,Education);
        std::cout<<std::endl;
        ptrEmployee.push_back(new Fresher(tmpid,std::move(tmpfullName),std::move(tmpbirthDay),std::move(tmpphone),
        std::move(tmpemail),std::move(tmpemtypestr),std::move(tmpGraduation_date),std::move(tmpGraduation_rank),std::move(Education)));
    }else{//extended data for Intern
        int tmpSemester ;std::string tmpemtypestr = "Intern";
        std::string tmpMajors,tmpUniversity_name;
        std::cin.ignore();
        std::cout << "Majors: ";
        std::getline(std::cin,tmpMajors);

        std::cout << "Semester: ";
        tmpSemester = getUint8();
        std::cin.ignore();

        std::cout << "University_name: ";
        std::getline(std::cin,tmpUniversity_name);
        std::cout<<std::endl;
        ptrEmployee.push_back(new Intern(tmpid,std::move(tmpfullName),std::move(tmpbirthDay),std::move(tmpphone),
        std::move(tmpemail),std::move(tmpemtypestr),std::move(tmpMajors),std::move(tmpSemester),std::move(tmpUniversity_name)));
    }
}

void managementEmployee::showListEmployee(){
    for(auto emp:ptrEmployee){
        emp->showMe();
    }
}

bool managementEmployee::checkEmptyIdEmployee(unsigned int id){
    for(auto ptr:ptrEmployee){
        if(ptr->getId() == id){
            return true;
        }
    }
    return false;
};

Employee* managementEmployee::getPtrEmployeeById(unsigned int id){
    for(auto ptr:ptrEmployee){
        if(ptr->getId() == id){
            return ptr;
        }
    }
    std::cout <<  "have no this id in list";
    return NULL;
}

unsigned int managementEmployee::getIndexEmployeeById(unsigned int id){
    for (unsigned int i = 0; i<ptrEmployee.size(); i++){
        if(ptrEmployee[i]->getId()==id){
            return i;
        }
    }
    std::cout << "have no this id in list";
    return 0;
};

void managementEmployee::editEmployeeById(unsigned int id){
    unsigned int indexID = getIndexEmployeeById(id);
    delete ptrEmployee[indexID];
    
    std::cout <<"----------------------------------------------------------------------\n";
    std::string tmpfullName, tmpbirthDay, tmpphone, tmpemail;
    unsigned int tmpid,tmpemtype;
    bool inforValid = false;
    tmpid = id;

    while(!inforValid){
        try {
            std::cout << "Enter Full Name: ";
            std::getline(std::cin, tmpfullName);
            validateFullName(tmpfullName);

            std::cout << "Enter Birthday (YYYY-MM-DD): ";
            std::cin >> tmpbirthDay;
            validateBirthDay(tmpbirthDay);

            std::cout << "Enter Phone number(10 digits): ";
            std::cin >> tmpphone;
            validatePhone(tmpphone);

            std::cout << "Enter Email: ";
            std::cin >> tmpemail;
            validateEmail(tmpemail);
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

    std::cout<<"Enter Employee Type 0: Experience, 1: Fresher , 2: Intern\n";
    do{
        std::cout << "Enter Type: ";
        std::cin >> tmpemtype;
    }while(!(tmpemtype == 0 || tmpemtype == 1 || tmpemtype == 2));

    if(tmpemtype == 0){//extended data for experiences
        int tmpexpInYear ;std::string tmpemtypestr = "Experience";
        std::string tmpProskill;

        std::cout << "Enter Expirence in years: ";
        tmpexpInYear = getUint8();
        std::cin.ignore();

        std::cout << "Enter Professional Skill: ";
        std::getline(std::cin,tmpProskill);
        ptrEmployee[indexID] = new Experience(tmpid,std::move(tmpfullName),std::move(tmpbirthDay),std::move(tmpphone),
        std::move(tmpemail),std::move(tmpemtypestr),tmpexpInYear,std::move(tmpProskill));
    }else if(tmpemtype == 1){//extended data for Freshers
        std::string tmpemtypestr = "Fresher";
        std::string tmpGraduation_date,tmpGraduation_rank,Education;
        std::cout << "Enter Graduation Date: ";
        std::cin.ignore();
        std::getline(std::cin,tmpGraduation_date);

        std::cout << "Enter Graduation Rank: ";
        std::getline(std::cin,tmpGraduation_rank);

        std::cout << "Enter Education: ";
        std::getline(std::cin,Education);
        std::cout<<std::endl;
        ptrEmployee[indexID] = new Fresher(tmpid,std::move(tmpfullName),std::move(tmpbirthDay),std::move(tmpphone),
        std::move(tmpemail),std::move(tmpemtypestr),std::move(tmpGraduation_date),std::move(tmpGraduation_rank),std::move(Education));
    }else{//extended data for Intern
        int tmpSemester ;std::string tmpemtypestr = "Intern";
        std::string tmpMajors,tmpUniversity_name;
        std::cin.ignore();
        std::cout << "Majors: ";
        std::getline(std::cin,tmpMajors);

        std::cout << "Semester: ";
        tmpSemester = getUint8();
        std::cin.ignore();

        std::cout << "University_name: ";
        std::getline(std::cin,tmpUniversity_name);
        std::cout<<std::endl;
        ptrEmployee[indexID] = new Intern(tmpid,std::move(tmpfullName),std::move(tmpbirthDay),std::move(tmpphone),
        std::move(tmpemail),std::move(tmpemtypestr),std::move(tmpMajors),std::move(tmpSemester),std::move(tmpUniversity_name));
    }
}

void managementEmployee::findExperience(){
    std::cout << "==========Experience Employee=========\n";
    bool has = false;
    for(auto ptr:ptrEmployee){
        if(ptr->getEmployee_Type() == "Experience")
        {
            ptr->showMe();
            has = true;
        }
    }
    if(!has){std::cout <<"List don't have any experience type!\n";}
};

void managementEmployee::findFresher(){
    std::cout << "============Fresher Employee===========\n";
    bool has = false;
    for(auto ptr:ptrEmployee){
        if(ptr->getEmployee_Type() == "Fresher")
        {
            ptr->showMe();
            has = true;
        }
    }
    if(!has){std::cout <<"List don't have any experience type!\n";}
};

void managementEmployee::findIntern(){
    std::cout << "============Intern Employee===========\n";
    bool has = false;
    for(auto ptr:ptrEmployee){
        if(ptr->getEmployee_Type() == "Intern")
        {
            ptr->showMe();
            has = true;
        }
    }
    if(!has){std::cout <<"List don't have any experience type!\n";}
};

void managementEmployee::deleteById(unsigned int id){
    if(!checkEmptyIdEmployee(id)){
        std::cout << "This id does not exist yet.\n";
    }else{
        ptrEmployee.erase(ptrEmployee.begin()+getIndexEmployeeById(id));
        std::cout << "This Employee had been delete.\n";
    }

};

