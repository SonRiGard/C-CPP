#include <iostream>
#include "officer.h"
#include <string>
using namespace std;

int main(){
    cout<< "program started";
    bool exit = false;
    int task = 0;
    managmentOfficer cp;
    while (!exit){
        do{
        cout<<"choose task:\n 1-add new officer \n 2-Seach by name \n 3-Show list officer \n 4-exit\n Your choice - ";
        cin >> task;
        cin.ignore();
        cout << endl;
        }
        while (task < 1 || task > 4) ;
    
        string name;int age;string sex; string address;  int type;

            switch (task)
            {
            case 1:
                cout << "Enter officer information:" << endl;    
                cout << "name: ";
                getline(std::cin, name);
                cout << endl;

                cout << "age: ";
                cin >> age;
                cin.ignore();
                cout << endl;
                       
                cout << "sex: ";
                getline(std::cin, sex);
                cout << endl;

                cout << "address: ";
                getline(std::cin, address);
                cout << endl;
                
                do{
                cout << "Type of officer: 1-worker; 2-engineer; 3-staff";
                cout << endl<< "type: ";
                cin >> type;
                cin.ignore();
                cout << endl;
                }
                while (type < 1 || type > 3);

                if (type == 1){
                    int level;
                    cout << "level : ";
                    cin >> level;
                    cin.ignore();
                    cout << endl;
                    cout<< name<< age<<sex<<address<<level;
                    officer* tmp = new worker(name,age,sex,address,level);
                    cp.addNew(tmp);
                }else{
                    if (type == 2){
                        string branch;
                        cout << "branch : ";
                        getline(cin,branch);
                        cout << endl;
                        cp.addNew(new engineer(name,age,sex,address,branch));
                    }
                    else{
                        string task;
                        cout << "task : ";
                        getline(cin,task);
                        cout << endl;
                        cp.addNew(new staff(name,age,sex,address,task));
                    }
                }
                cout << "show list";
                cp.shownList();
                break;
            case 2:
                cout << "Enter officer's Name: ";
                getline(cin,name);
                cp.searchByName(name);
                break;
            case 3:
                cp.shownList();
                break;
            case 4:
                exit = 1;
                break;
            } 

    }
}
