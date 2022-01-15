#include<bits/stdc++.h>
#define MAX 5
using namespace std;

class Deque{
private:
    int A[MAX];
    int front,rear;
public:
    Deque(){
        front = -1;
        rear = -1;
    }
    void enqueuefront(int );
    void enqueuerear(int );
    void dequeuefront();
    void dequeuerear();
    void print();

};

void Deque::enqueuefront(int xf){
    if((front==0 && rear==MAX-1) || (front==rear+1))
        cout<<"queue is full";
    else if(front == -1 && rear== -1){
        front=rear=0;
        A[front] = xf; //because we are inserting from front
    }
    else if(front == 0)
    {
        front = MAX -1;
        A[front] = xf;
    }
    else{
        front --;
        A[front] =xf;
    }
}

void Deque::enqueuerear(int xr){
     if((front==0 && rear==MAX-1) || (front==rear+1))
        cout<<"queue is full";
    else if(front == -1 && rear== -1){
        front=rear=0;
        A[rear] = xr; //because we are inserting from rear
    }
    else if(rear == MAX -1){
        rear = 0;
        A[rear] = xr;
    }
    else{
        rear++;
        A[rear] = xr;
    }
}

void Deque::dequeuefront(){
    if(front==-1 && rear == -1){
        cout<<"underflow condition";
        return;
    }
    else if(front == rear){
        front=rear= -1;
    }
    else if(front == MAX -1){
       front = 0;
    }
    else{
        front ++;
    }
}

void Deque::dequeuerear(){
    if(front==-1 && rear == -1){
        cout<<"underflow condition";
        return;
    }
    else if(front == rear){
        front=rear= -1;
    }
    else if(rear == 0){
        rear = MAX -1;
    }
    else{
        rear --;
    }
}

void Deque::print(){
    int i = front; //because we are printing from the front
    while(i!=rear){
        cout<<A[i]<<endl;
        i = (i+1)%MAX;
    }
    cout<<A[rear]; //to print rear value
}


int main(){
    Deque D;
    D.enqueuefront(2); // 0th index
    D.enqueuefront(5); //4th index
    D.enqueuerear(-1); //1st index
    D.enqueuerear(0); //2nd index
    D.enqueuefront(7); //3rd index because front-- i.e. 4-1 = 3
    D.print(); //final postion front = 3 rear =2 //displays in order 7 5 2 -1 0
    cout<<endl;
    cout<<" -------------"<<endl;
    D.dequeuefront(); // 7
    D.dequeuerear(); // 0
    D.dequeuefront(); // 5

    D.print(); //remaining value will be 2, -1

}
