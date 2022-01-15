#include<iostream>
using namespace std;

void towerOfHanoi(int n, char sourceRod, char destinationRod, char auxiliaryRod){
    if(n==1){
        cout<<"Move disk 1 from rod "<<sourceRod<<" to rod "<<destinationRod<<endl;
        return;
    }else{
        towerOfHanoi(n-1,sourceRod,auxiliaryRod,destinationRod);
        cout<<"Move disk "<<n<<" from rod "<<sourceRod<<" to rod "<<destinationRod<<endl;
        towerOfHanoi(n-1,auxiliaryRod,destinationRod,sourceRod);

    }
}

int main()
{
    int n;
    cout<<"enter the number of disks: ";cin>>n;
    towerOfHanoi(n,'A','C','B'); //  A=source,C=destination,B=auxiliary
    return 0;
}
