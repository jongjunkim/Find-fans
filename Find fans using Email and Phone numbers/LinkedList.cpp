#include "LinkedList.h"
using namespace std;
#include <iostream>


bool LinkedList::insert(Fan &newdata){

    Node *new_node = new Node(newdata);


   if(find(newdata.getPhone()) != nullptr){
       cout << "----duplicate Phone number----" << endl;
       return false;
   }

   if(find(newdata.getEmail()) != nullptr){
       cout << "----duplicate Email----" << endl;
       return false;
   }


    if (num_elements == 0) {
		assert(head == nullptr);
		assert(tail == nullptr);
		head = new_node;	
		tail = head;
        email.add(newdata.getEmail(), head);
        phone.add(newdata.getPhone(), head);
        num_elements++;
		return true;
	}
	assert(head != nullptr);
	assert(tail != nullptr);

    if(head == tail){
        head->next = new_node;
        email.add(newdata.getEmail(), new_node);
        phone.add(newdata.getPhone(), new_node);
        tail = new_node;
        tail->prev = head;
        num_elements++;
        return true;
    }
    
    tail->next = new_node;
    new_node->prev = tail;
    email.add(newdata.getEmail(), new_node);
    phone.add(newdata.getPhone(), new_node);
    tail = new_node;
    num_elements++;
    	
	return true;
}


 LinkedList::~LinkedList(){

     Node* newnode = head;

     while(head != nullptr){
         newnode = head;
         head = head->next;
         delete newnode;
     }


 }

void LinkedList::remove(const std::string &id){

    Phone p1;
    Email e1;

    Node* newnode = find(id); 

    if(newnode == nullptr){
        cout << "There isn't " << id << " in fans" << endl;
    }else if(newnode != nullptr){
        cout << "Removing fan "<< newnode->data << endl;
        p1 = newnode->data.getPhone();
        e1 = newnode->data.getEmail();
        email.removeTree(e1);
        phone.removeTree(p1);
        deleteNode(newnode);
        num_elements--;
    }
}

void LinkedList::deleteNode(Node * deleted){

    if(head == nullptr || deleted == nullptr)
        return;
    
    if(head == deleted)
        head = deleted->next;

    if(deleted->next != nullptr)
        deleted->next->prev = deleted->prev;

    if(deleted->prev != nullptr)
        deleted->prev->next = deleted->next;

    delete(deleted);

}


LinkedList::Node* LinkedList::find(const std::string &id){
    

    if(id[0] == '('){
        Node *np = phone.find(id);
        if(np != nullptr){
            return np;
            
        }else{
            return nullptr;
        }
    
    }else{
        Node *ni = email.find(id);
        
        if(ni != nullptr){
            return ni;
        }
        else{    
            return nullptr;
        }
    }

    return nullptr;

   
}

void LinkedList::addDollars(const std::string &id, const std::string &money){
    
     for(int i = 0; i<money.length(); i++){
            if(isdigit(money[i]) == 0){
                cout << " comprising only digits" << endl;
                return;
            }
        }

    Node *newnode = find(id);

    if(newnode == nullptr){
        cout << "There isn't " << id << " in fans" << endl;
    }else{
        newnode->data.setConcessions(money);
        cout << "Adding $" << money << " to " << id << "'s " << "spending total." << endl;  
    }

}


void LinkedList::writeFile(string output){

    ofstream outdata;

    outdata.open(output);

    if(!outdata){
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    
    for (Node *np = head; np != nullptr; np = np->next)
        outdata << np->data << endl;
    


    outdata.close();


}

 void LinkedList::showWithId(std::string id){


    Node *np = find(id);
     
    if(np != nullptr){
        cout << "Showing fan " << np->data << endl;
    }else{
        cout << "There isn't " << id << " in fans" << endl; 
    }
}

