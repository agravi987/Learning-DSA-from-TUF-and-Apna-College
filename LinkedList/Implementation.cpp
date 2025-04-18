// Implementation of Linked List in cpp  

#include<iostream>

using namespace std ; 

class Node {
public:
    int data ; 
    Node* next ; 

    Node(int val){
        data = val ; 
        next = nullptr ; 
    }
};

// Singly linked list class with head and tail 

class LinkedList{
private : 
    Node* head ; 
    Node* tail ; 

public:
    LinkedList(){
        head = nullptr ; 
        tail = nullptr ; 
    }

    // insert at the front 
    void push_front(int val){

        Node* newNode = new Node(val) ; 

        if(!head){
            head = tail = newNode ; 
        }else{
            newNode->next = head ; 
            head = newNode ; 
        }
    }

    // insert at the back 
    void push_back(int val){
        Node* newNode = new Node(val) ; 
        if(!head){
            head = tail = newNode ; 
        }else{
            tail->next = newNode ; 
            tail = newNode ; 
        }
    }

    // Delete from the front 

    void pop_front(){
        if(!head){
            cout << "list is empty" << endl ; 
            return ; 
        }

        Node* temp = head ; 
        head = head -> next ;
        delete temp ; 

        if(!head) tail = nullptr ;  // if list becomes empty 

    }

    // Delete from back 

    void pop_back(){
        if(!head){
            cout << "List is empty" << endl ; 
            return ; 
        }

        if(head == tail){
            delete head ; 
            head = tail = nullptr ; 
            return ; 
        }


        Node* temp = head ;
        while(temp->next != tail){
            temp = temp->next ; 
        }
        delete tail ; 
        tail = temp ; 
        tail->next = nullptr ; 

    }


    // Display the linkedlist 

    void display(){
        if(!head){
            cout << "List is empty" << endl ;
            return ; 
        }

        Node* temp = head; 
        while(temp){
            cout << temp->data << "->" ; 
            temp = temp->next ; 
        }

        cout << " NULL " ; 
    }

    ~LinkedList() {
        Node* temp ; 
        while(head){
            temp = head ; 
            head = head -> next ;
            delete temp ; 
        }

        tail = nullptr ; 
    }
};




int main(){

    LinkedList list ; 
     
    list.push_back(10) ;
    list.push_back(20) ;
    list.push_front(5);

    list.display() ; 

    list.pop_front(); 
    list.display() ; 

    list.pop_back(); 
    list.display() ; 
    
    return 0 ; 
}