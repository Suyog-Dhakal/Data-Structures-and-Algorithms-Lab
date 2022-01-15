#include<bits/stdc++.h>
#define MAX 5
using namespace std;

class CircularQueue{
    private:
        int A[MAX];
        int front, rear;
    public:
        CircularQueue(){
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

bool CircularQueue:: isEmpty(){
    return (front == -1 && rear == -1) ? true : false;
}

bool CircularQueue:: isFull(){
    return ((rear + 1)% MAX) == front ? true : false;
}

void CircularQueue:: enqueue(int x){

    if(isEmpty()){
        front=rear=0;
        //A[rear] =x;
    }
    else if(isFull()){
        cout<<"queue is full"<<endl;
    }
    else
    {
        rear = (rear + 1) % MAX;

    }
    A[rear] = x;
}

void CircularQueue::dequeue(){


    if (isEmpty()){
        cout<<"Empty queue"<<endl;
        return;
    }
    else if(front == rear){
        front=rear=-1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    cout<<endl;
}

int CircularQueue:: peek(){
    if(front == -1){
        cout<<"cannot return element from empty queue"<<endl;
    }
    return A[front];
}

void CircularQueue:: print(){
    int i = front;
    while(i != rear){
        cout<<A[i]<<endl;
        i = (i+1)%MAX;
    }
    cout<<A[rear];
}

int main(){
    CircularQueue Q;
    Q.enqueue(2);
    Q.enqueue(3);
    Q.print();
    cout<<endl<<"-----------";
    Q.dequeue();
    Q.enqueue(1);
    Q.enqueue(6);
    Q.print();

    return 0;
}
