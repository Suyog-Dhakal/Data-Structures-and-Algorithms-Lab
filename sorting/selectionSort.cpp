#include<iostream>
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int iMin = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[iMin])
                iMin = j;
        }
        int temp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = temp;
    }
}
int main()
{
    int arr[] = {3,2,5,8,4};
    selectionSort(arr,5);
    for(int i=0;i<5;i++)
        std::cout<<arr[i];
}