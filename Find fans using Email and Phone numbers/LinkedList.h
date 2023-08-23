#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Fan.h"
#include "assert.h"
#include "BST.h"


class LinkedList{
    private:
        class Node{
            public:
                Fan data;
                Node *next, *prev;

                Node(){
                    data = Fan();
                    next = nullptr;
                    prev = nullptr;
                }

                Node(const Fan &data){
                    this->data = data;
                    next = nullptr;
                    prev = nullptr;
                }

            
        };
        Node *head, *tail;
        unsigned num_elements;
        BST<Email, Node*> email;
        BST<Phone, Node*> phone;

    public:
        LinkedList(){head = tail = nullptr; num_elements=0;};
        ~LinkedList();
        bool insert(Fan &newdata);
        void remove(const std::string &id);
        Node* find(const std::string &id);
        void deleteNode(Node * deleted);
        void show();
        void showWithId(std::string id);
        void showWithId();
        void writeFile(std::string output);
        void addDollars(const std::string &id, const std::string &money);
        unsigned getNum(){
            return num_elements;
        }


};

#endif
