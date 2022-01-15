
#include<iostream>
using namespace std;
#define MAX_SIZE 100

class Stack{
private:
    int A[MAX_SIZE]; //array to store the stack
    int top;
public:
    Stack(){
    top = -1; //for empty array
    }

    void push(int x){
    if(top == MAX_SIZE -1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    A[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout<<"no element to pop"<<endl;
            return;
        }
        top--;
    }

    int Isempty(){
    if(top == -1)
        return 1;
    return 0;
    }

    void print(){
        cout<<"Stack"<<endl;
        for(int i=0;i<=top;i++){
            cout<<A[i]<<endl;
        }
    }
};

int main(){
    Stack s;
    s.push(2); s.print();
    s.push(3); s.print();
    s.pop(); s.print();
    s.push(5); s.print();

}
