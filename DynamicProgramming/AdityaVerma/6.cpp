// You are given an array arr[] of size n containing positive integers and an integer value diff. Your task is to count the number of subsets of arr such that the difference between the sum of elements of the two subsets is equal to diff.

#include<bits/stdc++.h>
using namespace std;

int usingRecursion(int*arr, int n, int target){
    if(target == 0) return 1;
    if(n==0) return 0;
    if(target < arr[n-1]) return usingRecursion(arr, n-1, target);
    return usingRecursion(arr, n-1, target - arr[n-1]) + usingRecursion(arr, n-1, target);
}

int usingMemoisation(int*arr, int n, int target, vector<vector<int>> &dp){
    if(target == 0) return 1;
    if(n==0) return 0;

    if(dp[n][target] != -1) return dp[n][target];
    if(target >= arr[n-1]){
        dp[n][target] = usingMemoisation(arr, n-1, target - arr[n-1], dp) + usingMemoisation(arr, n-1, target, dp);
    }
    else{
        dp[n][target] = usingMemoisation(arr, n-1, target, dp);
    }
    return dp[n][target];
}

int usingDP(int*arr, int n, int target, vector<vector<int>> &dp){
    for(int i=0; i<=target; i++) dp[0][i] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(j >= arr[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

int main(){
    int n, d, sum=0;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int*arr = new int[n];
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<"Enter the difference : ";
    cin>>d;
    int target = (sum + d)/2;
    cout<<"Solving using recursion : "<<usingRecursion(arr, n, target)<<endl;
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    cout<<"Solving using memoisation : "<<usingMemoisation(arr, n, target, dp)<<endl;
    dp = vector<vector<int>>(n+1, vector<int>(target+1, -1));    
    cout<<"Solving using DP : "<<usingDP(arr, n, target, dp)<<endl;
    return 0;
}