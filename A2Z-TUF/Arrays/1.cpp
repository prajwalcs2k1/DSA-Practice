// Write a C++ program to print the largest element in an array

#include<bits/stdc++.h>
using namespace std;

int findLar(int*arr, int n){
    int mx = INT_MIN;
    for(int i=0; i<n; i++) mx = max(mx, arr[i]);

    return mx;
}

int main(){
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array cannot be empty!!\n";
        return 0;
    }
    cout<<"Enter the array elements : ";
    int *arr = new int[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<"Largest element in the array is : "<<findLar(arr, n)<<endl;
    delete[] arr;
    return 0;
}