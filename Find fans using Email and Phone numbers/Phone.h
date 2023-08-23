#ifndef PHONE_H
#define PHONE_H
#include <string>
#include <ctype.h>
#include <iostream>

class Phone{

    private:
        std::string area;
        std::string number;
        std::string phoneNumber;

    public:
        Phone();
        Phone(std::string pnumber);
        bool checkPhone(std::string pnumber);
        
        std::string getArea(){
            return area;
        }
        std::string getNumber(){
            return number;
        }
        
        std::string getPhonNumber(){
            return phoneNumber;
        }
    
        friend std::ostream& operator <<(std::ostream& output, const Phone phone){
            output << phone.phoneNumber;
            return output;
        }

        bool operator <(const Phone &p);
        bool operator ==(const Phone &p);
            
            
        

};

#endif