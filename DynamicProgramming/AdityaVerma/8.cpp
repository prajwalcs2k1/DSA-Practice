// Write a C++ program to solve Rod Cutting problem
/*
    You are given:
        - A rod of length N.
        - An array price[], where price[i] represents the price of a rod of length i + 1.

    Your task is to:
        - Determine the maximum total value obtainable by cutting up the rod and selling the pieces.
        - You may cut the rod into any number of pieces of integer lengths, or you can choose not to cut it at all.
*/

#include<bits/stdc++.h>
using namespace std;

int usingRecursion(int*len, int*prices, int rod, int n){
    if((rod == 0) || (n == 0)) return 0;

    int notTake = usingRecursion(len, prices, rod, n-1);
    int take = 0;
    if(rod >= len[n-1]){
        take = prices[n-1];
        take += usingRecursion(len, prices, rod - len[n-1], n);
    }

    return max(take, notTake);
}

int usingDP(int*len, int *prices, int rod, int n, vector<vector<int>>&dp){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=rod; j++){
            if(j >= len[i-1]){
                dp[i][j] = max(dp[i-1][j], prices[i-1] + dp[i][j - len[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][rod];
}


int main(){

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int *len = new int[n];
    int *prices = new int[n];
    cout<<"Enter the lengths : ";
    for(int i=0; i<n; i++) cin>>len[i];

    cout<<"Enter the prices : ";
    for(int i=0; i<n; i++) cin>>prices[i];

    int t,rod;        
    cout<<"Enter the no. of tests : ";
    cin>>t;

    while(t--){
        cout<<"Enter the rod length : ";
        cin>>rod;
        cout<<"Solving using recursion : "<<usingRecursion(len, prices, rod, n)<<endl;
        vector<vector<int>>dp(n+1, vector<int>(rod+1, 0));
        cout<<"Solving using DP : "<<usingDP(len, prices, rod, n, dp)<<endl;
    }

    return 0;
}