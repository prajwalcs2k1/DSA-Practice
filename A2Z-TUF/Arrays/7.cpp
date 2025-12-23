// Write a C++ program to move all the 0's to the end of the array while maintaining the relative order of the non-zero elements

#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int *arr, int n){
    int zInd = 0;
    for(int i=0; i<n; i++){
        while((zInd < n) && (arr[zInd] != 0)) zInd++;
        if(arr[i] && (zInd < i)) swap(arr[i], arr[zInd]);
    }
    return;
}

int main(){

    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array can't be empty!!\n";
        return 0;
    }
    int*arr = new int[n];
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++) cin>>arr[i];
    moveZeroes(arr, n);
    cout<<"Array elements after updation : ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    delete[] arr;
    return 0;
}