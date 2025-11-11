// Given an array of positive integers arr[] of size n, determine whether it can be partitioned into two subsets such that the sum of the elements in both subsets is equal.

#include<bits/stdc++.h>
using namespace std;

bool usingRecursion(int*arr, int n, int sum){
    if(sum == 0) return true;
    if(n <= 0) return false;
    if(arr[n-1] <= sum){
        return usingRecursion(arr, n-1, sum - arr[n-1]) || usingRecursion(arr, n-1, sum);
    }

    return usingRecursion(arr, n-1, sum);
}

bool usingMemoization(int*arr, int n, int sum, vector<vector<int>> & dp){
    if(sum == 0) return true;
    if(n <= 0) return false;
    if(dp[n][sum] != -1) return dp[n][sum];
    if(arr[n-1] <= sum){
        dp[n][sum] = usingMemoization(arr, n-1, sum - arr[n-1], dp) || usingMemoization(arr, n-1, sum, dp);
    }
    else dp[n][sum] = usingMemoization(arr, n-1, sum, dp);
    return dp[n][sum];
}

int main(){

    int n, sum=0;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int * arr = new int[n];
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    if(sum % 2){
        cout<<"Sum of the array elements is odd, hence no valid subsets present!!\n";
        return 0;
    }
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    cout<<"Solving using recursion : "<<(usingRecursion(arr, n, sum/2) ? "2 equal subsets exists.\n" : "Subsets do not exists!!\n");
    cout<<"Solving using memoisation : "<<(usingMemoization(arr, n, sum/2, dp) ? "2 equal subsets exists.\n" : "Subsets do not exists!!\n");
    return 0;
}