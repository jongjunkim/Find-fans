#include "Phone.h"
#include <iostream>
using namespace std;


Phone::Phone(){
    area = "";
    number = "";
    phoneNumber = "";
}

Phone::Phone(string pnumber){

    string phone;
    phoneNumber = pnumber;
    
    for(char c:pnumber){
        if(std::isdigit(c) != 0)
          phone += c;
    }
    area = phone.substr(0,3);
    number = phone.substr(3, phone.length()-1);

}

bool Phone::checkPhone(string pnumber){

    string phone;

    if(!(pnumber[0] == '(' && pnumber[4] == ')' && pnumber[8] == '-')){
        cout << "wrong input for phone number" << endl;
        return false;;
    }
    
    for(char c:pnumber){
        if(std::isdigit(c) != 0)
            phone += c;
    }

    if(!(phone.length() == 10)){
        cout << "phone number should be integer." << endl;
        return false;
    }

    return true;

}


bool Phone::operator <(const Phone &p){
            
    if(area < p.area){
        return true;
    }
    return false;
}

bool Phone::operator ==(const Phone &p){

    if(phoneNumber == p.phoneNumber){
        return true;
    }
    return false;

}