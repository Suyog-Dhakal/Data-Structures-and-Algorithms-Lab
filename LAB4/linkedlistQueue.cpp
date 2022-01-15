#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    int data;
    Node *next,*front,*rear;
public:
    Node(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int);
    void dequeue();
    void display();
};

void Node::enqueue(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front=rear=temp;
        return;
    }else{
        rear->next = temp;
        rear = temp;
    }
}

void Node::dequeue(){
    Node* temp = front;
    if(front == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    if(front == rear){
        front=rear=NULL;
    }
    else{
        front = front->next;
    }
    delete temp;
}

void Node::display(){
    Node *temp = front;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node Queue;
    Queue.enqueue(10); Queue.display();
    Queue.enqueue(20); Queue.display();
    Queue.enqueue(30); Queue.display();
    Queue.dequeue(); Queue.display();
    cout<<endl;

}
