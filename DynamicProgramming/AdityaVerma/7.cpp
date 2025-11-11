// Write a C++ program to solve unbounded knapsack problem
/*
    You are given N items, where each item i has:
        - a weight wt[i]
        - a value val[i]
    You are also given a knapsack that can carry a maximum weight of W.
    The unbounded knapsack problem is to determine the maximum total value that can be obtained by selecting items such that:
        - The total weight does not exceed W
        - Any item can be chosen an unlimited number of times
*/

#include<bits/stdc++.h>
using namespace std;

int usingRecursion(int *wts, int *vals, int n, int W){
    if(W == 0) return 0;
    if(n == 0) return 0;
    int take = 0;
    int notTake = usingRecursion(wts, vals, n-1, W);
    
    if(W >= wts[n-1]){
        take = vals[n-1];
        take += usingRecursion(wts, vals, n, W-wts[n-1]);
    }

    return take > notTake ? take : notTake;
}

int usingMemoisation(int *wts, int *vals, int n, int W, vector<vector<int>> &dp){
    if((W == 0) || (n == 0)) {
        dp[n][W] = 0;
        return dp[n][W];
    }

    if(dp[n][W] != -1) return dp[n][W];

    int notTake = usingMemoisation(wts, vals, n-1, W, dp);
    int take = 0;
    if(W >= wts[n-1]){
        take = vals[n-1];
        take += usingMemoisation(wts, vals, n, W-wts[n-1], dp);
    }

    dp[n][W] = max(take, notTake);
    return dp[n][W];
}

int usingDP(int *wts, int *vals, int n, int W, vector<vector<int>> &dp){

    for(int i=0; i<=W; i++) dp[0][i] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(j >= wts[i-1]){
                dp[i][j] = max(dp[i-1][j], vals[i-1] + dp[i][j - wts[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main(){

    int n, W;
    cout<<"Enter the array size : ";
    cin>>n;
    int *vals = new int[n];
    int *wts = new int[n];
    cout<<"Enter the weights of the items : ";
    for(int i=0; i<n; i++) cin>>wts[i];
    cout<<"Enter the values of the items : ";
    for(int i=0; i<n; i++) cin>>vals[i];

    int t;
    cout<<"Enter the no. of tests : ";
    cin>>t;
    while(t--){
        cout<<"Enter the knapsack capacity : ";
        cin>>W;
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        cout<<"Solving using recursion : "<<usingRecursion(wts, vals, n, W)<<endl;
        cout<<"Solving using memoisation : "<<usingMemoisation(wts, vals, n, W, dp)<<endl;
        dp = vector<vector<int>>(n+1, vector<int>(W+1, 0));
        cout<<"Solving using DP : "<<usingDP(wts, vals, n, W, dp)<<endl;
    }

    return 0;
}