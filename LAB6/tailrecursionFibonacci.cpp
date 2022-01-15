#include<iostream>
using namespace std;

int fibonacciTailRecursion(int n, int a=0,int b=1){
    if(n==0)
        return a;
    if(n==1)
        return b;
    return fibonacciTailRecursion(n-1,b,a+b);
}

int main()
{
    int n,i=0;
    cout<<"enter the number of terms for series: ";cin>>n;
    cout<<endl<<"fibonacci series is: ";
    while(i<n){
        cout<<" "<<fibonacciTailRecursion(i);
        i++;
    }
    return 0;
}
