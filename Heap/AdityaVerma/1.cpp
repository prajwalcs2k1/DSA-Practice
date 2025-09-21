// Write a C++ program to print the Kth smallest element from a given array

#include<bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int> &arr, int n, int K){
    priority_queue<int> maxH;
    for(int ele : arr){
        maxH.push(ele);
        if(maxH.size() > K) maxH.pop();
    }
    return maxH.top();
}

int main(){

    int n, K;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of K : ";
    cin>>K;
    if((K <= 0) || (K > n)){
        cout<<"Invalid K value provided!!\n";
        return 0;
    }
    cout<<K<<" smallest element is : "<<findKthSmallest(arr, n, K)<<endl;
    return 0;
}