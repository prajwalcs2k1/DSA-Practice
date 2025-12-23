// Write a C++ program to rotate the input array to the left by K steps

#include<bits/stdc++.h>
using namespace std;

void rotateArr(vector<int>&arr, int n, int K){

    K = K % n;
    if(!K) return;

    reverse(arr.begin(), arr.begin() + K);
    reverse(arr.begin() + K, arr.end());
    reverse(arr.begin(), arr.end());

    return;
}


int main(){

    int n, K;
    cout<<"Enter the array size: ";
    cin>>n;
    if(!n){
        cout<<"Array cannot be empty!!\n";
        return 0;
    }

    vector<int> arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Enter the value of K: ";
    cin>>K;
    rotateArr(arr, n, K);
    cout<<"Array after rotating "<<K<<" steps to the left: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}