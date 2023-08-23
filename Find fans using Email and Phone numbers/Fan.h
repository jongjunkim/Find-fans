#ifndef FAN_H
#define FAN_H
#include <string>
#include <sstream>
#include <fstream>
#include "Phone.h"
#include "Email.h"

class Fan{

    private:
        std::string lastName;
        std::string firstName;
        Phone phone;
        Email email;
        std::string seat;
        std::string concessions;

    public:     
        Fan();
        Fan(std::string lname, std::string fname, Phone phon, Email emai, std::string sea, std::string con);
        void print();
        bool check(std::string last, std::string first, std::string money);
        friend std::ostream& operator << (std::ostream& output, Fan fan);
        std::string getPhone(){
            return phone.getPhonNumber();
        }
        std::string getEmail(){
            return email.getEmailAddress();
        }
        void setConcessions(std::string money){
            int num1 = stoi(money);
            int num2 = stoi(concessions);
            int num3 = num1 + num2;
            concessions = std::to_string(num3);

        }



};

#endif