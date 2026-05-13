// Write a C++ program to find the Kth smallest element from the given array

#include<bits/stdc++.h>
using namespace std;

int KthSmallest(vector<int> &arr, int n, int K){
    priority_queue<int> pq;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);

        if(pq.size() > K) pq.pop();
    }

    return pq.top();
}

int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];

    int K;
    cout<<"Enter the value of K: ";
    cin>>K;

    if((K <= 0) || (K > n)){
        cout<<"Invalid K value!\n";
        return 0;
    }

    // T.C. is O(N*log(K))
    cout<<K<<"th smallest from the input array is: "<<KthSmallest(arr, n, K)<<endl;

    return 0;
}