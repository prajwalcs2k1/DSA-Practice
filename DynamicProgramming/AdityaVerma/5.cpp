// You are given an array arr[] of positive integers with size n. You need to partition this array into two subsets S1 and S2 such that the absolute difference of their sums is minimum possible.

#include<bits/stdc++.h>
using namespace std;

void usingRecursion(vector<int> &arr, int n, int totalSum, int currSum, int &mn){
    // if(n <= 0) return;
    // if(((mn == INT_MAX) && (currSum != 0)) || (mn != INT_MAX)){
    //     mn = min(mn, abs(currSum - totalSum));
    // }

    if(n == 0){
        int diff = totalSum - (2*currSum);
        diff = abs(diff);
        mn = min(mn, diff);
        return;
    }

    // usingRecursion(arr, n-1, totalSum - arr[n-1], currSum + arr[n-1], mn);
    usingRecursion(arr, n-1, totalSum, currSum + arr[n-1], mn);
    usingRecursion(arr, n-1, totalSum, currSum, mn);
    return;
}

int usingMemoisation(vector<int> & arr, int n, int totalSum, int currSum, vector<vector<int>> &dp){
    if(n==0){
        int diff = abs(totalSum - currSum);
        return diff;
    }

    if(dp[n][currSum] != -1) return dp[n][currSum];

    dp[n][currSum] = min(usingMemoisation(arr, n-1, totalSum-arr[n-1], currSum + arr[n-1], dp) , usingMemoisation(arr, n-1, totalSum, currSum, dp));
    return dp[n][currSum];
}

int usingDP(vector<int> &arr, int n, int totalSum, vector<vector<int>> &dp){
    
}

int main(){

    int n, totalSum=0, currSum=0;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
        totalSum += arr[i];
    }

    int mn = INT_MAX;
    usingRecursion(arr, n, totalSum, currSum, mn);
    cout<<"Solving using recursion : "<<mn<<endl;
    vector<vector<int>> dp(n+1, vector<int>(totalSum+1, -1));
    mn = usingMemoisation(arr, n, totalSum, currSum, dp);
    cout<<"Solving using memoisation : "<<mn<<endl;
    dp = vector<vector<int>>(n+1, vector<int>(totalSum+1, INT_MAX));
    mn = usingDP(arr, n, totalSum, dp);
    cout<<"Solving using DP : "<<mn<<endl;
    return 0;
}