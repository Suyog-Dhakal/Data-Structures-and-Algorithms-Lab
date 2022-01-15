#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *previous;
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;
public:
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    void addBeginning(int);
    void addEnd(int);
    void insertAfter(int,int);
    void insertBefore(int,int);

    void deleteBeginning();
    void deleteEnd();
    void deleteAfter(int);
    void deleteBefore(int);

    void display();
};

void DoublyLinkedList::addBeginning(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->previous = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
    return;
}

void DoublyLinkedList::addEnd(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->previous = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
    }
    return;
}

void DoublyLinkedList::insertAfter(int data, int nodeNum){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->previous = NULL;

    Node *ptr = head;
    for(int i=1;i<nodeNum;i++){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->previous = ptr;
    ptr->next->previous = temp;
    ptr->next = temp;

    return;
}

void DoublyLinkedList::insertBefore(int data, int nodeNum){
    Node *temp = new Node();
    temp->data = data;
    temp->previous = NULL;
    temp->next = NULL;

    Node *ptr = head;
    if(nodeNum == 1){
        addBeginning(data);
    }else{
        insertAfter(data, nodeNum-1);
    }

    return;
}

void DoublyLinkedList::deleteBeginning(){
    if(head == NULL){cout<<"Empty list"<<endl;}
    Node *temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp;
    return;

}

void DoublyLinkedList::deleteEnd(){
    if(head == NULL){cout<<"Empty"<<endl;}
    Node *temp = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete temp;
    return;

}

void DoublyLinkedList::deleteAfter(int nodeNum){
    Node *ptr = head;
    for(int i=1;i<nodeNum;i++){
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next->previous = ptr;
    delete temp;
    return;
}

void DoublyLinkedList::deleteBefore(int nodeNum){
    if(nodeNum == 1){
        cout<<"error"<<endl;
    }else if(nodeNum == 2){
        deleteBeginning();
    }else{
        deleteAfter(nodeNum -2);
    }
    return;

}

void DoublyLinkedList::display(){
    Node *ptr = head;
    if(ptr == NULL){
        cout<<"empty list"<<endl;
        return;
    }
    while(ptr != NULL){
        cout<<ptr->data<<"  ";
        ptr = ptr->next;
    }
    cout<<endl;
    return;
}

int main()
{
    DoublyLinkedList D1;
    D1.addBeginning(10); D1.display();
    D1.addBeginning(5); D1.display();
    D1.addBeginning(13); D1.display();
    D1.addEnd(20); D1.display();
    D1.insertAfter(15,2); D1.display();
    D1.insertBefore(12,2); D1.display();
    D1.deleteBeginning(); D1.display();
    D1.deleteEnd(); D1.display();
    D1.deleteAfter(1); D1.display();
    D1.deleteBefore(3); D1.display();
}






