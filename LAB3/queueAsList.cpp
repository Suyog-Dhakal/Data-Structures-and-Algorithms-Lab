#include<iostream>
#define MAX 2
using namespace std;

class Queue{
private:
    int A[MAX];
    int front,rear;
public:
    Queue(){
        front=rear=-1;
    }
    void insert(int x);
    void remove();
    void print();
};

void Queue::insert(int x){
    if(rear== MAX-1){
        cout<<"full"<<endl;
   }
   else if(front==-1 && rear==-1){
    front=rear=0;
    A[rear] = x;
    cout<<x<<"inserted"<<endl;
   }
   else{
    rear++;
    A[rear] = x;
    cout<<x<<" inserted"<<endl;
   }
}

void Queue::remove(){
    if(front==rear==-1){
        cout<<"nothing to remove"<<endl;
    }
    else {
        int value = A[front ++];
        cout<<value<<" removed"<<endl;
    }
}


void Queue::print(){
    for(int i= front; i < rear+1;i++){
        cout<<A[i]<<endl;
    }
}


int main()
{
    Queue q;
    q.insert(5);
    q.insert(10);
    q.insert(3); //full condition
    q.remove(); //5 removed
    q.insert(7); //still full condtition
    q.print(); //10 printed

}
