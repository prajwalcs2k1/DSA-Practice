// Write a C++ program to print maximum of all subarrays of size K

#include<bits/stdc++.h>
using namespace std;

vector<int> bruteForce(int n, vector<int>&arr, int K){
    int mx = INT_MIN;
    vector<int>res;
    for(int i=0; i<=n-K; i++){
        for(int j=i; j<i+K; j++) mx = max(mx, arr[j]);
        res.push_back(mx);
        mx = INT_MIN;
    }
    return res;
}

vector<int> optimisedApp(int n, vector<int>&arr, int K){
    vector<int>res;
    if(K <= 0 || K > n) return res;
    deque<int>dq;
    int mx = INT_MIN;

    int st = 0, en = 0;
    while(en < n){
        while(!dq.empty() && arr[dq.back()] <= arr[en]) dq.pop_back();
        dq.push_back(en);
        if((en - st + 1) == K){
            res.push_back(arr[dq.front()]);
            st++;
            while(dq.front() < st) dq.pop_front();
        }
        en++;
    }
    return res;
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
    vector<int>res;
    res = bruteForce(n, arr, K);
    for(auto it: res) cout<<it<<" ";
    cout<<"\n";

    res = optimisedApp(n, arr, K);
    for(auto it: res) cout<<it<<" ";
    cout<<"\n";

    return 0;
}