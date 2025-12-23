// Write a C++ program to find the second largest number from an array. If the second-largest element does not exist, return -1.

#include<bits/stdc++.h>
using namespace std;

int findSecLar(vector<int> & arr, int n){
    int secLar = -1;
    int firstLar = -1;

    for(int i=0; i<n; i++){
        if(arr[i] > firstLar){
            secLar = firstLar;
            firstLar = arr[i];
        }
    }

    return secLar;
}

int main(){

    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array cannot be empty!!\n";
        return 0;
    }
    vector<int> arr(n);
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Second largest element from the array is : "<<findSecLar(arr, n)<<endl;
    return 0;
}