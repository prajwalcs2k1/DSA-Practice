// Write a C++ program to print the number which appears only once in an array where the remaining elements appears twice

#include<bits/stdc++.h>
using namespace std;

int singleAppear(int*arr, int n){
    int res = 0;
    for(int i=0; i<n; i++) res = res ^ arr[i];
    return res;
}

int main(){

    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array can't be empty!!\n";
        return 0;
    }
    int *arr = new int[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<singleAppear(arr, n)<<" is the number which appears only once in the array.\n";

    return 0;
}