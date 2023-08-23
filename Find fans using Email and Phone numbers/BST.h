#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template<class T, class V>
struct Node{

    T data;
    Node *left;
    Node *right;
    V link;

    Node(T data, V link){
        this->data = data;
        this->link = link;
        left = nullptr;
        right = nullptr; 
    }
        

};

template <class T, class V>
class BST{

    private:

        Node<T,V> *root;
        unsigned int num;

    public: 

        BST(){
            root = nullptr;
            num = 0;
        }

        
        ~BST(){
            destructor(root);
        }

        void destructor(Node<T,V> *node){
            
            if(node != nullptr){
                destructor(node->left);
                destructor(node->right);     
                delete node;   
            }
            
        }

        void add(T val, V linked){
            root = insert(val, linked, root);
        }

        Node<T,V>* insert(T val, V linked, Node<T,V> *root){

            if(root == nullptr){
                root = new Node<T,V>(val,linked);
            }else if(val < root->data){
                root->left = insert(val, linked, root->left);
            }else{
                root->right = insert(val, linked, root->right);
            }
            return root;
        }

         void printInorder(){
            inorder(root);
           
        }

        void inorder(Node<T,V> *root){
            if(root == nullptr)
                return;

            inorder(root->left);
            cout << root->data << endl;
            inorder(root->right);
        }

        V find(T key){

            V linked = search(root, key);

            if(linked == nullptr)
                return nullptr;
            else{  
                return linked;
            }
             
        }

        V search(Node<T,V> *root, T key){

           
            if(root == nullptr){
                return nullptr;
            }

            if(root->data == key){
                return root->link;
            }
            
            if(root->data < key){
                return search(root->right, key);
            }else{
                return search(root->left, key);
            }
        }

        bool removeTree(T key){
            
            V linked = search(root, key);
            
            if(linked == nullptr)
                return false;
             
            deleteTree(root, key);
            
            return true;
                
        }

        Node<T,V>* deleteTree(Node<T,V> *root, T val){
            
             if(root == nullptr)
                return root;

            if(val < root->data)
                root->left = deleteTree(root->left, val);
            else if(root->data < val)
                root->right = deleteTree(root->right, val);
            else{
                
                if(root->left == nullptr && root->right == nullptr)
                    return nullptr;
                
                else if(root->left == nullptr){
                    Node<T,V> *temp = root->right;
                    delete(root);
                    return temp;
                }
                
                else if(root->right == nullptr){
                    Node<T,V> *temp = root->left;
                    delete(root);
                    return temp;
                }

                Node<T,V> *temp = minNode(root->right);

                root->data = temp->data;

                root->right = deleteTree(root->right, temp->data);

            }

            return root;

        }


        Node<T,V>* minNode(Node<T,V>* node){
            
            Node<T,V>* temp = node;

            while(temp && temp->left != nullptr)
                temp = temp->left;

            return temp;
        }


};

#endif