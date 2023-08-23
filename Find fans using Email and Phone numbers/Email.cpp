#include "Email.h"
#include <iostream>
using namespace std;


Email::Email(){
    name = "";
    address = "";
    emailAddress = "";
}

Email::Email(string email){
    emailAddress = email;
    string::size_type pos = email.find('@');
    name = email.substr(0,pos);
    address = email.substr(pos+1);
 
}

bool Email::checkEmail(string mail){

    int count = 0;
    int countperiod = 0;

    string::size_type pos = mail.find('@');
    string temp_address = mail.substr(pos+1);

    for(int i = 0; i< mail.length(); i++){
        if(mail[i] == '@')
            count++;
    }

    for(int i = 0; i<temp_address.length(); i++){
        if(temp_address[0] == '.')
            break;
        if(temp_address[i] == '.')
            countperiod++;
    }

    
    if(!(count == 1 && countperiod >= 1)){
        cout << "bad input for email" << endl;
        return false;
    }
    
    return true;
        
}

bool Email::operator ==(const Email &e){
    if(emailAddress == e.emailAddress){
        return true;
    }
    return false;
}


bool Email::operator <(const Email &e){

    int compare = name.compare(e.name);
    
    if(compare < 0){
        return true;
    }
    return false;
}


