#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    int data;
    Node* next;
    Node* top;
public:
    Node(){
    top = NULL;
    }
    void push(int);
    void pop();
    void display();
};

void Node::push(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
    return;
}

void Node::pop(){
    if(top == NULL){
        cout<<"Stack underflow"<<endl;
    }

    Node* temp;
    temp = top;
    top = top->next;
    delete temp;
}

void Node::display(){
     if(top == NULL){cout<<"Nothing to display"<<endl;}
    Node* temp = top;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node Stack;
    Stack.push(5); Stack.display();
    Stack.push(10); Stack.display();
    Stack.push(15); Stack.display();
    Stack.pop(); Stack.display();

    return 0;
}
