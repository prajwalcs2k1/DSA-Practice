// Write a C++ program to solve Coin Change problem
/*
    You are given:
        - An integer array coins[] where each element represents a denomination of a coin.
        - An integer amount representing the total amount of money you want to make.

    You need to determine:
        - Coin Change (Minimum Coins) → the minimum number of coins required to make up that amount. (If it’s not possible, return -1.)

    👉 Example: coins = [1, 2, 5], amount = 11
    → Output: 3 (because 11 = 5 + 5 + 1)
*/

#include<bits/stdc++.h>
using namespace std;

int usingRecursion(int*denom, int n, int C){
    if(C == 0) return 0;
    if((C < 0) || (n == 0)) return -1;
    
    int notTake = usingRecursion(denom, n-1, C);
    int take = -1, res;

    if(C >= denom[n-1]){
        res = usingRecursion(denom, n, C - denom[n-1]);
        if(res != -1){
            take = 1 + res;         // initialise the value of take only if res if valid else let take be equal to -1 
        }
    }

    if((notTake == -1) && (take == -1)) return -1;
    if(notTake == -1) return take;
    if(take == -1) return notTake;
    return min(take, notTake);
}

int usingMemoisation(int*denom, int n, int C, vector<vector<int>> &dp){
    if(C == 0) return 0;
    if((n <= 0) || (C < 0)) return -1;

    if(dp[n][C] != -2) return dp[n][C];

    int notTake = usingMemoisation(denom, n-1, C, dp);
    int take = -1;

    if(C >= denom[n-1]){
        int res = usingMemoisation(denom, n, C - denom[n-1], dp);
        if(res != -1){
            take = 1 + res;
        }
    }

    if((notTake == -1) && (take == -1)) dp[n][C] = -1;
    else if(take == -1) dp[n][C] = notTake;
    else if(notTake == -1) dp[n][C] = take;
    else dp[n][C] = min(take, notTake);
    return dp[n][C];
}

int usingDP(int*denom, int n, int C, vector<vector<int>>&dp){
    for(int i=0; i<=C; i++) dp[0][i] = -1;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=C; j++){
            if(j >= denom[i-1]){
                int take = dp[i][j - denom[i-1]];
                int notTake = dp[i-1][j];
                if(take != -1) take += 1;
                if((take != -1) && (notTake != -1)) dp[i][j] = min(take, notTake);
                else dp[i][j] = take == -1 ? notTake : take;
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
        cout<<"solving using recursion : "<<usingRecursion(denom, n, C)<<endl;

        vector<vector<int>>dp(n+1, vector<int>(C+1, -2));
        cout<<"solving using memoisation : "<<usingMemoisation(denom, n, C, dp)<<endl;

        dp = vector<vector<int>>(n+1, vector<int>(C+1, 0));
        cout<<"Solving using DP : "<<usingDP(denom, n, C, dp)<<endl;
    }
    return 0;
}