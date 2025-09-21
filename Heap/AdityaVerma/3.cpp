// Write a C++ program to sort a K sorted array using Heap

#include<bits/stdc++.h>
using namespace std;

void sortArr(vector<int> &arr, int n, int K){

    priority_queue<int, vector<int>, greater<int>> minH;
    for(int i=0; i<min(n, K+1); i++){
        minH.push(arr[i]);
    }
    for(int i=0; i<n; i++){
        arr[i] = minH.top();
        minH.pop();
        if((i+1+K) < n){
            minH.push(arr[i+1+K]);
        }
    }
    cout<<"Sorted array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return;
}

int main(){

    int n, K;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the value of K : ";
    cin>>K;
    vector<int> arr(n);
    cout<<"Enter the K sorted array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortArr(arr, n, K);
    return 0;
}