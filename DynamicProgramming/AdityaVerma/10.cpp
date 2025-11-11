// Write a C++ program to solve Coin Change problem
/*
    You are given:
        - An integer array coins[] where each element represents a denomination of a coin.
        - An integer amount representing the total amount of money you want to make.

    You need to determine:
        - Coin Change (Number of Ways) → the number of distinct combinations of coins that can make up that amount.

    👉 Example: coins = [1, 2, 5], amount = 5
    → Output: 4
    (Combinations: {5}, {2,2,1}, {2,1,1,1}, {1,1,1,1,1})
*/

#include<bits/stdc++.h>
using namespace std;

int usingRecursion(int*denom, int n, int C){
    if(C == 0) return 1;
    if((n <= 0) || (C < 0)) return 0;
    int take = 0;
    int notTake = usingRecursion(denom, n-1, C);

    if(C >= denom[n-1]){
        take = usingRecursion(denom, n, C - denom[n-1]);
    }
    return take + notTake;
}

int usingMemoisation(int*denom, int n, int C, vector<vector<int>> & dp){
    if(C == 0) return 1;
    if((n <= 0) || (C < 0)) return 0;
    if(dp[n][C] != -1) return dp[n][C];
    int notTake = usingMemoisation(denom, n-1, C, dp);
    int take = 0;
    if(C >= denom[n-1]){
        take = usingMemoisation(denom, n, C - denom[n-1], dp);
    }
    dp[n][C] = take + notTake;
    return dp[n][C];
}

int usingDP(int*denom, int n, int C, vector<vector<int>> &dp){
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=C; j++){
            if(j >= denom[i-1]){
                dp[i][j] = dp[i-1][j] + dp[i][j - denom[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][C];
}

int main(){

    int n;
    cout<<"Enter the size of coins denominations array : ";
    cin>>n;

    int *denom = new int[n];
    cout<<"Enter the denominations : ";
    for(int i=0; i<n; i++) cin>>denom[i];

    int t, C;
    cout<<"Enter the no. of tests : ";
    cin>>t;
    while(t--){
        cout<<"Enter the amount : ";
        cin>>C;
        cout<<"Solving using recursion : "<<usingRecursion(denom, n, C)<<endl;
        vector<vector<int>> dp(n+1, vector<int>(C+1, -1));
        cout<<"Solving using memoisation : "<<usingMemoisation(denom, n, C, dp)<<endl;
        dp = vector<vector<int>>(n+1, vector<int>(C+1, 0));
        cout<<"Solving using DP : "<<usingDP(denom, n, C, dp)<<endl;
    }
    return 0;
}