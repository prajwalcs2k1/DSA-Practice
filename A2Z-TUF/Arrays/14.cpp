// Write a C++ program to find the length of the longest subarray that sums to K. If no such subarray exists then return 0.

#include<bits/stdc++.h>
using namespace std;

int subArraySum(int*arr, int n, int K){
    int res = 0, currSum = 0;
    unordered_map<int, int> mp;

    mp[0] = -1; // very important

    for(int i=0; i<n; i++){
        currSum += arr[i];
        if(mp.find(currSum - K) != mp.end()) res = max(res, (i - mp[currSum - K]));

        if(mp.find(currSum) == mp.end()) mp[currSum] = i;
    }
    return res;
}

int main(){

    int n, K;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array can't be empty!!\n";
        return 0;
    }
    int *arr = new int[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Enter the value K: ";
    cin>>K;

    cout<<"Subarray with length "<<subArraySum(arr, n, K)<<" has sum equal to "<<K<<endl;


    delete[] arr;
    return 0;
}