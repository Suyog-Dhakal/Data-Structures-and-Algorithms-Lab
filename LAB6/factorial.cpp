#include<iostream>
using namespace std;

unsigned int factorial(unsigned int n){
    if(n==0)
        return 1;
    return(n*factorial(n-1));
}

int main()
{
    int n;
    cout<<"enter the number:";cin>>n;
    cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl;
    return 0;
}
