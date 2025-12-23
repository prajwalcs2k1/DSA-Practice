// Write a C++ program to find the smallest index where the target appears in the array. If the target is not found then return -1

#include<bits/stdc++.h>
using namespace std;

int findTar(int*arr, int n, int tar){

    for(int i=0; i<n; i++) if(arr[i] == tar) return i;

    return -1;
}

int main(){

    int n, tar;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array can't be empty!!\n";
        return 0;
    }
    int*arr = new int[n];
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Enter the target element : ";
    cin>>tar;
    int res = findTar(arr, n, tar);
    if(tar == -1){
        cout<<tar<<" is not found in the array!\n";
    }
    else{
        cout<<"Smallest index of "<<tar<<" in the array is: "<<res<<"\n";
    }
    delete[] arr;
    return 0;
}