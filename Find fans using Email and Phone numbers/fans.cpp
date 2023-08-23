#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "BST.h"
#include "Fan.h"
#include <sstream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "Parser.h"
#include <vector>

void readCommand(string fileName, vector<string> &commandf){

    string text;
    string space = " ";

    ifstream newfile(fileName);
        if(!newfile)
            cerr << "Error: file could not be opened" << endl;
        else{ 
            while(getline(newfile, text)){
                string::size_type pos = text.find(space);
                if(text.substr(0,pos) == "Process"){
                    readCommand(text.substr(pos+1) , commandf);
                }else{
                    commandf.push_back(text);
                }
            }
        }
        
}


bool readfile(string fileName, LinkedList &linked){

    ifstream fin(fileName);
    string last;
    string first;
    string number;
    string address;
    string where;
    string discount;
    string line;
    Phone p1;
    Email e1;
    Fan f1;

    if(!fin){
        cerr << "Error: file could not be opened" << endl;
        return false;
    }

    int count = 1;

    while(getline(fin,line)){
        stringstream ss(line);

        ss >> last >> first >> number >> address >> where >> discount;

        if(!(f1.check(last, first, discount))){
            cout << "   Invalid input on line " << count << endl;
            return false;
        }
        
        if(p1.checkPhone(number))
            p1 = Phone(number);
        else{
            cout << "   Invalid input on line " << count << endl;
            return false; 
        }
        if(e1.checkEmail(address))
            e1 = Email(address);
        else{   
            cout << "   Invalid input on line " << count << endl;
            return false;
        }
        f1 = Fan(last, first, p1, e1, where, discount); 
    
        if(linked.insert(f1)){
            cout  << "Line   "<< count << ":" << last << " " << first << " " << number << " "<< address << " " <<where << 
               " " << discount << endl;
            count++;
        }else{
            cout  << "Line   "<< count << ":" << last << " " << first << " " << number << " "<< address << " " <<where << 
               " " << discount << endl;
            count++;
        }
      
    
    }
    fin.close();
    return true;
    
}



int main(int argc, char* argv[]){


    int o;
    LinkedList link;
    string command;
    string line;
    Phone ph;
    Email em;
    Fan fa;
    string inputFile;
    string outputFile;

    vector<string> commandfile;
    int loop =0;
  



    bool userinputFile = false;
    bool useroutputFile = false;

     const char *optstring = "i:o:";

    while((o = getopt(argc,argv,optstring)) != -1){
        switch(o){
            case 'i':
                inputFile = argv[2];
                userinputFile = true;
                readfile(inputFile, link);
                break;
            
            case 'o' :
                outputFile = argv[4];
                useroutputFile = true;
                break;
            
            case '?':
                printf("error optopt: %c\n", optopt);
                printf("error opterr: %c\n", opterr);
                break;
        }
    }
 
    if(!userinputFile){
        inputFile = "fans.in.txt";
        readfile(inputFile,link);
        cout << "Loaded " <<  link.getNum() << " fans from " << inputFile << endl;
    }
    
    if(!useroutputFile)
        outputFile = "fans.out.txt";


    while(1){

        cout << endl << "Enter a command" << endl;
        cout << "Choose from " << endl;
        cout << "Load <input-filename>" << endl;
        cout << "Show <fan-id>" << endl;
        cout << "Spend <fan-id> <dollars>" << endl;
        cout << "Remove <fan-id>" << endl;
        cout << "Process <command-filename>" << endl;
        cout << "Quit" << endl;
        cout << ":";


        if(loop == commandfile.size()){
            loop = 0;
            commandfile.clear();     
        }



        if(commandfile.size() == 0)
            getline(cin, line);
        else{
            line = commandfile.at(loop);
            cout << commandfile.at(loop) << endl;  
            loop++;
             
        }
        Parser command(line);

       
        
        
        if(command.getOperation().empty()){
            if(std::cin.fail())
                break;
            continue;
        }

        if(command.getOperation() == "Quit"){
            if(command.numArgs() > 0){
                cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
            }
            link.writeFile(outputFile);
            cout << "Stored " << link.getNum() << " fans into " << outputFile << endl;
            break;
        
        }else if(command.getOperation() == "Load"){
            if(command.numArgs() == 1){
                cout << "Loading file " << command.getArg1() << endl;
                readfile(command.getArg1(), link);

            }
            if(command.numArgs() > 1){
                if(command.numArgs() == 6){
                    fa = Fan(command.getArg1(), command.getArg2(), command.getArg3(), command.getArg4(), 
                            command.getArg5(),command.getArg6());
                    link.insert(fa);
                }else
                    cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            }
            if(command.numArgs() < 1)
                cout << std::endl << "Can't operate with missing arguments" << endl; 
                //readfile(inputFile, link, bstEmail, bstPhone);
             
        }else if(command.getOperation() == "Show"){
            if(command.numArgs() < 1)
                cout << std::endl << "Can't operate with missing arguments" << endl; 
            else if(command.numArgs() > 1)
                 cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            else{
                
                link.showWithId(command.getArg1());
                  
            }
              
         }else if(command.getOperation() == "Spend"){
            if(command.numArgs() < 2)
                cout << std::endl << "Can't operate with missing arguments" << endl; 
            else if(command.numArgs() > 2)
                cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            else{
               link.addDollars(command.getArg1(), command.getArg2()); 
            }
        }else if(command.getOperation() == "Remove"){
            
            if(command.numArgs() < 1)
                cout << std::endl << "Can't operate with missing arguments" << endl; 
            else if(command.numArgs() > 1)
                cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            else{
                
               link.remove(command.getArg1());
            }
        
        }else if(command.getOperation() == "Process"){
            if(command.numArgs() < 1)
                cout << std::endl << "Can't operate with missing arguments" << endl; 
            else if(command.numArgs() > 1)
                cout << std::endl <<  "Ignoring " << UNEXPECTED_ARGS << endl;
            else{
                cout << "Processing file " << command.getArg1() << endl;
                readCommand(command.getArg1(), commandfile);  
        
            }
        }else{
            cout << std::endl << "Command not recognized. Please try again. " << endl;
        }
      
    }   


   

    
    
    return 0;
}