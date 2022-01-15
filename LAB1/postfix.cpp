/*operands must be integers and there should be space in between two operands.
only +,-,*,/ operators are accepted */

#include<iostream>
#include<stack>
#include<string>
using namespace std;


bool IsOperator(char C){
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    else
        return false;
}


int PerformOperation(char operation, int operand1, int operand2){
    if(operation == '+') return (operand1 + operand2);
    else if(operation == '-') return (operand1 - operand2);
    else if(operation == '*') return (operand1 * operand2);
    else if(operation == '/') return (operand1 / operand2);

    else cout<<"Unexpected error"<<endl;

}

int EvaluatePostfix(string expression){
    stack<int> S;

    for(int i=0; i<expression.length(); i++){
        if(expression[i] == ' ' || expression[i] == ',')
            continue;
        else if(IsOperator(expression[i])){
            int operand2 = S.top(); S.pop();
            int operand1 = S.top();S.pop();
            int result = PerformOperation(expression[i],operand1, operand2);
            S.push(result);
        }

    }
    return S.top();
}

int main(){
    string expression;
    cout<<"Enter Postfix expression \n";
    getline(cin,expression);
    int result = EvaluatePostfix(expression);
    cout<<"Result is = "<<result<<endl;
    return 0;

}
