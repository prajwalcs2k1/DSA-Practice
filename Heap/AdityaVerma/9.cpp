// Write a C++ program to print the sum of all the numbers between K1th and K2th smallest number from the array

#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int> & arr, int n, int K){
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size() > K) pq.pop();
    }

    return pq.top();
}

int findSum(vector<int> & arr, int n, int K1, int K2){
    int ans = 0;
    int v1, v2;
    if(K1 > K2) swap(K1, K2);
    v1 = findKthSmallest(arr, n, K1);
    v2 = findKthSmallest(arr, n, K2);
    for(int i=0; i<n; i++){
        if((arr[i] > v1) && (arr[i] < v2)) ans += arr[i];
    }
    return ans;
}


int main(){

    int n, K1, K2;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the K1 & K2 values: ";
    cin>>K1>>K2;
    if(K1 <= 0 || K2 <= 0 || K1 > n || K2 > n) {
        cout << "Invalid K values!" << endl;
        return 0;
    }
    cout<<"Sum of elements are = "<<findSum(arr, n, K1, K2)<<endl;
    return 0;
}