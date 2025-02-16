#include <iostream>
#include <string.h>
#include "officer.h"

using namespace std;


int managmentOfficer::addNew(officer* obj){
    if (obj == NULL){
        cout << "ptr list officer == null";
        return 0;
    }
    listOfficer.push_back(obj);
    return 0;
}
void managmentOfficer::searchByName(string name){
    for (auto officer : listOfficer){
        if(officer->getName() == name){
            officer->printOff();
        }
    }
}
void managmentOfficer::shownList(){
    if (listOfficer.isEmpty()) {
        std::cout << "Danh sách cán bộ rỗng!\n";
        return;
    }
    for (auto officer : listOfficer){
        officer->printOff();
        cout << "----------------------" << endl;
    }
}
void managmentOfficer::exit (){

}