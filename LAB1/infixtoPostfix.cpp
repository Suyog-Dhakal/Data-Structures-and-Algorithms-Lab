
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class Stack{
private:
    int top;
    char A[MAX];
public:
    Stack(){
        top = -1;
    }

   bool push(char data);
   char pop();
    char Top();
    bool isEmpty();
    bool isFull();
};

bool Stack::push(char data){
    if(top == MAX -1){
        cout<<"stack overflow"<<endl;
        return false;
    }
    A[++top] = data;
    return true;
}

char Stack::pop(){
   if(top == -1){
    cout<<"stack underflow"<<endl;
    return 0;
   }
   A[top--];
   return 0;
}

char Stack::Top(){
if(top > -1){
    return A[top];
}
else{
    cout<<"empty stack"<<endl;
    return 0;
}
}

bool Stack:: isEmpty(){
return (top < 0);
}

bool Stack::isFull(){
    return (top == MAX);
}

int getPrecedence(char op){
    switch(op){
        case '^':
            return 3;
            break;

        case '*':
        case '/':
        case '%':
            return 2;
            break;

        case '+':
        case '-':
            return 1;
            break;

        default:
            return -1;
    }
}

void infixToPostfix(char *exp){
    Stack s;
    char postfix[strlen(exp)];
    int LengthofPostfix = 0;
    s.push('(');

    for(int i = 0 ; i < strlen(exp); i++){
        if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){
            postfix[LengthofPostfix++] = exp[i];
        }
        else if(exp[i] == '('){
            s.push(exp[i]);
        }
        else if(exp[i] == ')'){
            while(s.Top() != '('){
                    postfix[LengthofPostfix++] = s.pop();
                  }
                  s.pop();
        }
        else {
            if(getPrecedence(exp[i]) < getPrecedence(s.Top())){
                while(s.Top() != '(' && getPrecedence(exp[i]) < getPrecedence(s.Top())){
                        postfix[LengthofPostfix++] = s.pop();
                      }
            }
            s.push(exp[i]);
        }
    }
    cout<<postfix<<endl;
}

int main() {
    char expression[] = "A-(B-(C-D))";
    strcat(expression, ")");
    infixToPostfix(expression);
}
