#include<iostream>
using namespace std;

unsigned factorialTailRecursion(unsigned int n, unsigned int a){
    if(n==0)
        return a;
    return factorialTailRecursion(n-1,n*a);
}

unsigned int factorial(unsigned int n){
    return factorialTailRecursion(n,1);
}

int main(){
    int n;
    cout<<"enter the number:";cin>>n;
    cout<<"The factorial of "<<n<<" is: "<<factorial(n);
    return 0;
}
