#include "managementStudents.h"
#include "exception.h"
#include "input.h"
#include <ctime>   
#include <cstdlib>

managementStudents::managementStudents(){

};

managementStudents::~managementStudents(){
    for(auto ptr:ptrStudents){
        delete ptr;
    }
};

void managementStudents::showInforStudents(){
    for(auto ptr:ptrStudents){
        ptr->ShowMyInfor();
    }
};

void managementStudents::shownSortedListNameAndPhone(){
    auto swap = [](auto*& A, auto*& B){
        auto* tmp = A;
        A=B;
        B=tmp;
    };

    int size = ptrStudents.size();
        // + sort normal
    for(int i=0; i<size;i++)
    {
        for (int j = i+1; j < size;j++ )
        {
            if (
                ptrStudents[j]->getFullname() > ptrStudents[i]->getFullname() ||
            (ptrStudents[j]->getFullname() > ptrStudents[i]->getFullname() && ptrStudents[j]->getPhone()<ptrStudents[j]->getPhone())
            ){
                swap(ptrStudents[i],ptrStudents[j]);
            }
        }
    }
    for(auto ptr:ptrStudents){
        ptr->ShowNameAndPhone();
    }
};    

void managementStudents::addStudent(){
    std::cout <<"----------------------------------------------------------------------\n";
    std::string tmpfullName,tmpsex, tmpDOB, tmpPhone,tmpUniversity,tmpgradeLevel,tmp;
    int tmpType,tmptypeSex;//for type students(good/normal)
    bool inforValid=false;

    while(!inforValid){
        try {
            std::cout << "Enter Full Name: ";
            std::getline(std::cin, tmpfullName);
            InvalidFullNameException(tmpfullName);

            std::cout << "Enter Birthday (DD-MM-YYYY): ";
            std::getline(std::cin, tmpDOB);
            InvalidDOBException(tmpDOB);

            do
            {
                std::cout << "Sex : (0 - female; 1 - male)";
                tmptypeSex = getUint8();
                std::cin.ignore();
            } while (!(tmptypeSex == 0 || tmptypeSex == 1));
            
            
            switch ((sexTypeEnum)tmptypeSex)
            {
            case female:
                tmpsex = "female";
                break;
            case male:
                tmpsex = "male";
                break;
            default:
                throw std::runtime_error("Input files have unknow errors !!!\n");
                break;
            }

            std::cout << "Enter Phone number(10 digits): ";
            std::getline(std::cin, tmpPhone);
            InvalidPhoneNumberException(tmpPhone);

            std::cout << "Enter University Name: ";
            std::getline(std::cin, tmpUniversity);
            
            std::cout << "Enter Grade Level: ";
            std::getline(std::cin, tmpgradeLevel);
            #ifdef BEBUGMODE
            std::cout << "\nValidate Information!\n";
            std::cout << "Name: " << fullName << "\nBirthday: " << birthDay << "\nPhoneNumber: " << phone << "\nEmail: " << email << endl;
            #endif
            inforValid = true;
        } 
        catch (const std::exception& e) {
            std::cout << "\nError: " << e.what() << std::endl;
        }

    } 

    std::cout<<"Enter Student Type 0: Good, 1: Normal\n";
    do{
        std::cout << "Enter Type: ";
        tmpType = getUint8();
    }while(!(tmpType == 0 || tmpType == 1));

    switch ((studentTypeEnum)tmpType)
    {
    case good:{
        float tmpgpa;
        std::cout << "Enter GPA (float): ";
        std::cin >> tmpgpa;
        std::cin.ignore();

        std::string tmpreward;
        std::cout << "Best reward Name: ";
        std::getline(std::cin,tmpreward);
        std::cout << std::endl;

        ptrStudents.push_back(new GoodStudent(std::move(tmpfullName),std::move(tmpDOB),
        std::move(tmpsex),std::move(tmpPhone),std::move(tmpUniversity),
            std::move(tmpgradeLevel),tmpgpa,std::move(tmpreward)));

        break;
    }
    case normal:{
        int tmpenglishScore;
        std::cout << "Enter English Score(int): ";
        std::cin >> tmpenglishScore;
        std::cin.ignore();

        float entryTestScore;
        std::cout << "Enter Entry Test Score (float): ";
        std::cin >> entryTestScore;
        std::cin.ignore();
        std::cout << std::endl;

        ptrStudents.push_back(new NormalStudent(std::move(tmpfullName),std::move(tmpDOB),
        std::move(tmpsex),std::move(tmpPhone),std::move(tmpUniversity),
            std::move(tmpgradeLevel),tmpenglishScore,entryTestScore));

        break;
    }
    default:
        std::cout << "Unknown type of student" <<std::endl;
        break;
    }
};

void managementStudents::sortStudents(){

};

void managementStudents::selectCandidates(int n){
    std::vector<GoodStudent*> ptr_goodStudents;
    std::vector<NormalStudent*> ptr_normalStudents;
    std::vector<Student*> selectedStudents;
    int num = ptrStudents.size();//get all students

    if(n>num){
        std::cout << "Number of all student smaller than needed \n" << std::endl;
        for (Student* ptr:ptrStudents){
            ptr->ShowNameAndPhone();
        }
        return;
    }

    for(auto ptr:ptrStudents){
        switch (ptr->getType())
        {
        case good:
            ptr_goodStudents.push_back(dynamic_cast<GoodStudent*>(ptr));
            break;

        case normal:
            ptr_normalStudents.push_back(dynamic_cast<NormalStudent*>(ptr));
            break;
        default:
            std::cout << "Unknow type Student.";
            break;
        }
    }

    int numGood = ptr_goodStudents.size();
    int numNormal = ptr_normalStudents.size();
    //lambda function wap 2 Pointer in list student Using in sort function
    auto swap = [](auto*& A, auto*& B){
        auto* tmp = A;
        A=B;
        B=tmp;
    };

    if(numGood< n){//if good <needed 
        for(Student* ptr:ptr_goodStudents) selectedStudents.push_back(ptr);//-> add all good students
        // + sort normal
        for(int i=0; i<numNormal;i++)
        {
            for (int j = i+1; j < numNormal;j++ ){
                if (
                    ptr_normalStudents[j]->getEntryScore() > ptr_normalStudents[i]->getEntryScore() || // if entry > hoac entry == and enghlish score > 
                (ptr_normalStudents[j]->getEntryScore() > ptr_normalStudents[i]->getEntryScore() && ptr_normalStudents[j]->getEnghlishScore()>ptr_normalStudents[j]->getEnghlishScore())
                ){
                    swap(ptr_normalStudents[i],ptr_normalStudents[j]);
                }
            }
        }
        //add remain needed students (neened - goodStudent)
        for (int i=0; i< (n - numGood);i++){
            selectedStudents.push_back(ptr_normalStudents[i]);
        }
    }else // sort good list and add needed number of students to selected LIST
    {
        // + sort good
        for(int i=0; i<numGood;i++)
        {
            for (int j = i+1; j < numGood;j++ ){
                if (
                ptr_goodStudents[j]->getGPA() > ptr_goodStudents[i]->getGPA() || // if gpa j>i hoacj gpa j=i => Ten a<ten B(A<B)
                (ptr_goodStudents[j]->getGPA() > ptr_goodStudents[i]->getGPA() && ptr_goodStudents[j]->getFullname()<ptr_goodStudents[j]->getFullname())
                ){
                    swap(ptr_goodStudents[i],ptr_goodStudents[j]);
                }
            }
        }
        //add sorted good students to list selected
        for (int i=0; i<n; i++){
            selectedStudents.push_back(ptr_goodStudents[i]);
        }
    }
    std::cout<< "======== LIST SELECTED STUDENTS ======";
    for(auto ptr:selectedStudents){
        ptr->ShowMyInfor();
    }
    std::cout<< "====== END LIST SELECTED STUDENTS ======";
};

void managementStudents::autoAddStudent() {
    static int count = 1; // Bien dem de tao du lieu duy nhat
    static bool isSeeded = false; 
    
    if (!isSeeded) {
        std::srand(std::time(0));
        isSeeded = true;
    }
    
    std::string tmpfullName = "SinhVien" + std::to_string(count);
    
    // Sinh ngay sinh ngau nhien
    int day = 1 + (std::rand() % 28);   
    int month = 1 + (std::rand() % 12); 
    int year = 1995 + (std::rand() % 11); 
    std::string tmpDOB = (day < 10 ? "0" : "") + std::to_string(day) + "-" +
                         (month < 10 ? "0" : "") + std::to_string(month) + "-" +
                         std::to_string(year);
    
    // Sinh so dien thoai ngau nhien
    std::string tmpPhone = "0" + std::to_string(100000000 + (std::rand() % 900000000));
    
    std::string tmpUniversity = "DaiHoc_" + std::to_string(count);
    std::string tmpgradeLevel = "CapBac_" + std::to_string(count);
    
    // Gioi tinh ngau nhien
    std::string tmpsex = (std::rand() % 2 == 0) ? "Nu" : "Nam";
    
    // Loai sinh vien ngau nhien (0: Gioi, 1: Thuong)
    int tmpType = std::rand() % 2;
    
    switch ((studentTypeEnum)tmpType) {
    case good: {
        float tmpgpa = 5.0 + (std::rand() % 51) / 10.0; 
        std::string tmpreward = "PhanThuongXuatSac";
    
        ptrStudents.push_back(new GoodStudent(std::move(tmpfullName), std::move(tmpDOB),
            std::move(tmpsex), std::move(tmpPhone), std::move(tmpUniversity),
            std::move(tmpgradeLevel), tmpgpa, std::move(tmpreward)));
    
        std::cout << "Da them sinh vien Gioi: " << tmpfullName << " - Ngay sinh: " << tmpDOB
                  << " - GPA: " << tmpgpa << std::endl;
        break;
    }
    case normal: {
        int tmpenglishScore = 50 + (std::rand() % 51); 
        float entryTestScore = 5.0 + (std::rand() % 51) / 10.0; 
    
        ptrStudents.push_back(new NormalStudent(std::move(tmpfullName), std::move(tmpDOB),
            std::move(tmpsex), std::move(tmpPhone), std::move(tmpUniversity),
            std::move(tmpgradeLevel), tmpenglishScore, entryTestScore));
    
        std::cout << "Da them sinh vien Thuong: " << tmpfullName << " - Ngay sinh: " << tmpDOB
                  << " - Diem Anh: " << tmpenglishScore << " - Diem dau vao: " << entryTestScore << std::endl;
        break;
    }
    default:
        std::cout << "Loi: Loai sinh vien khong hop le!" << std::endl;
        break;
    }
    
    count++; // Tang bien dem de tao sinh vien moi
    
}
