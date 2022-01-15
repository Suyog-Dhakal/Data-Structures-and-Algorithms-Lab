#include<bits/stdc++.h>
#define MAX 5
using namespace std;

class Queue{
    private:
        int A[MAX];
        int front, rear;
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool isEmpty();
        bool isFull();
        void enqueue(int x);
        void dequeue();
        int peek();
        void  print();
};

bool Queue:: isEmpty(){
    return (front == -1 && rear == -1) ? true : false;
}

bool Queue:: isFull(){
    return (rear + 1) == front ? true : false;
}

void Queue:: enqueue(int x){
    cout<<"Enqueing"<<endl;
    if(isFull()){
        cout<<"queue is full"<<endl;
        return;
    }
   else if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = rear + 1;

    }
    A[rear] = x;
}

void Queue::dequeue(){
    cout<<"Dequeing"<<endl;
    if(isEmpty()){
        cout<<"empty queue"<<endl;
        return;
    }
   else if (front == rear){
        front=rear= -1;
    }
    else
    {
        front =front+1;
    }
}

int Queue:: peek(){
    if(front == -1){
        cout<<"cannot return element from empty queue"<<endl;
    }
    return A[front];
}

void Queue:: print(){
    for(int i= front; i < rear+1;i++){
        cout<<A[i]<<endl;
    }
}


int main(){
    Queue Q;
    Q.enqueue(2); Q.print();
    Q.enqueue(4); Q.print();
    Q.dequeue() ; Q.print();
    Q.enqueue(8); Q.print();

    return 0;
}
