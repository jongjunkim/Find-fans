#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <string.h>

class Email{

    private:
        std::string name;
        std::string address;
        std::string emailAddress;


    public:
        Email();
        Email(std::string email);
        bool checkEmail(std::string mail);
        bool operator <(const Email &e);
        bool operator ==(const Email &e);


        std::string getName(){
            return name;
        }
        
        std::string getAddress(){
            return address;
        }

        std::string getEmailAddress(){
            return emailAddress;
        }

        friend std::ostream& operator <<(std::ostream& output, const Email email){
            output << email.emailAddress;
            return output;
        }

       

};

#endif