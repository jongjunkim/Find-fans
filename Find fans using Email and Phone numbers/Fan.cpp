#include "Fan.h"
#include <iostream>
using namespace std;

Fan::Fan(){

    lastName = "";
    firstName = "";
    phone = Phone();
    email = Email();
    seat = "";
    concessions = -1;

}

Fan::Fan(string lname, string fname, Phone phon, Email emai, string sea, string con){
    
    lastName = lname;
    firstName = fname;
    phone = phon;
    email = emai;
    seat = sea;
    concessions = con;
}

void Fan::print(){

    cout << lastName << " " << firstName << " " << phone.getArea() << " " << phone.getNumber() <<
        " " << email.getName() << " " << email.getAddress() << " " << seat << " " << concessions << endl;
}

std::ostream& operator << (std::ostream& output, Fan fan){

    output << fan.lastName << " " << fan.firstName << " " << fan.phone << " " << fan.email << " " 
            << fan.seat << " " << fan.concessions;
    return output;
}

bool Fan::check(std::string last, std::string first, std::string money){

        if(isupper(last[0]) == 0){
            cout << " '" << last << "' ";
            cout << "Lastname should start with a captical letter" << endl;
            return false;
        }

        if(isupper(first[0]) == 0){
            cout << " '" << first << "' ";
            cout << " Firstname should start with a capitcal letter" << endl;
            return false;
        }

        for(int i = 0; i< last.length(); i++){
            if(isalpha(last[i]) == 0){
                cout << "Lastname may include only letters" << endl;
                return false;
            }
        }

        for(int i = 0; i < first.length(); i++){
            if(isalpha(first[i]) == 0){
                cout << "Firstname may include only letters" << endl;
                return false;
            }
        }

        for(int i = 0; i<money.length(); i++){
            if(isdigit(money[i]) == 0){
                cout << " comprising only digits" << endl;
                return false;
            }
        }

        return true;

}

