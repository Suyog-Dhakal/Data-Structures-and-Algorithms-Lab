#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (!isalpha(c) && !isdigit(c));
}
 int getPrecedence(char C){
    if(C == '-' || C == '+')
        return 1;
    else if(C == '*' || C == '/')
        return 2;
    else if(C == '^')
        return 3;
    return 0;
 }

 string infixToPostfix(string infix){
    infix = '(' + infix + ')';
    stack<char> stk;
    string output;

    for(int i=0; i<infix.length(); i++){
        if(isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if(infix[i] == '(')
                stk.push('(');
        else if(infix[i] == ')'){
            while(stk.top() != '('){
                    output += stk.top();
                    stk.pop();
                  }
                  stk.pop(); //remove '(' from stack
        }
        else {
            if(isOperator(stk.top())){
                while(getPrecedence(infix[i]) <= getPrecedence(stk.top()))
                    output += stk.top();
                    stk.pop();
            }
            //pushing current operator in stack
            stk.push(infix[i]);
        }
    }
    return output;
 }

 string infixToPrefix(string infix){
    reverse(infix.begin(), infix.end());
    for(int i=0;i<infix.length();i++){
        if(infix[i] == '('){
            infix[i] = ')';
            i++;
           }
           else if(infix[i] == ')'){
            infix[i] = '(';
            i++;
           }
    }

    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(),prefix.end());

    return prefix;
 }

 int main(){
    string exp =  ("(a-b/c)*(a/k-l)");
    cout<<infixToPrefix(exp)<<endl;
    return 0;
 }
