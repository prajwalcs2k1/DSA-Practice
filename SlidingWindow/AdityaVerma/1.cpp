// Write a C++ program to find Maximum Sum Subarray of size K

#include<bits/stdc++.h>
using namespace std;

int bruteForce(int n, vector<int>&arr, int K){
    int ans = 0;
    for(int i=0; i<=(n-K); i++){
        int sum = 0;
        for(int j=i; j<(i+K); j++){
            sum += arr[j];
        }
        ans = max(ans, sum);
    }
    return ans;
}

int slidingWindow(int n, vector<int>&arr, int K){
    if(!K || K<0 || K>n) return 0;
    int ans = 0;
    int sum = 0;
    for(int i=0; i<K; i++){
        sum += arr[i];
    }
    if(K == n) return sum;
    ans = max(ans, sum);
    for(int i=K; i<n; i++){
        sum = sum + arr[i] - arr[i-K];
        ans = max(ans, sum);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    if(!n){
        cout<<"Array size cannot be 0!!\n";
        return 0;
    }
    vector<int>arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    int K;
    cout<<"Enter the K size: ";
    cin>>K;
    cout<<"Maximum sum subarray of size "<<K<<" is: "<<bruteForce(n, arr, K)<<endl;
    cout<<"Maximum sum subarray of size "<<K<<" is: "<<slidingWindow(n, arr, K)<<endl;
    return 0;
}