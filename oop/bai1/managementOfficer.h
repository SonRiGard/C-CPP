#ifndef MANAGEMENT_OFFICER_H_
#define MANAGEMENT_OFFICER_H_
#include "officer.h"
class managmentOfficer {
    private:
        vector<officer*> listOfficer; 
        
    public:
        int addNew(officer* obj);
        void searchByName(string name);
        void shownList();

        ~managmentOfficer(){
            std::cout << "Deleting list officer..." << std::endl;
            for (auto obj : listOfficer) {
                std::cout << "Delete: " << std::endl;
                delete obj;
            }
            listOfficer.clear();
        }
};
#endif