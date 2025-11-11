// Write a C++ program to find the length of the longest common subsequence when 2 strings are given

#include<bits/stdc++.h>
using namespace std;

int usingRecursion(string s1, string s2, int n, int m){
    if(!n || !m) return 0;
    int ans = 0;
    if(s1[n-1] == s2[m-1]){
        ans = 1 + usingRecursion(s1, s2, n-1, m-1);
    }else{
        ans = max(usingRecursion(s1, s2, n, m-1), usingRecursion(s1, s2, n-1, m));
    }
    return ans;
}

int usingMemoisation(string s1, string s2, int n, int m, vector<vector<int>>&dp){
    if(!n || !m) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    int ans = 0;
    if(s1[n-1] == s2[m-1]){
        ans = 1 + usingMemoisation(s1, s2, n-1, m-1, dp);
    }else{
        ans = max(usingMemoisation(s1, s2, n, m-1, dp), usingMemoisation(s1, s2, n-1, m, dp));
    }

    dp[n][m] = ans;
    return dp[n][m];
}

int usingDP(string s1, string s2, int n, int m, vector<vector<int>>&dp){
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) dp[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int main(){

    string s1,s2;
    cout<<"Enter the string1 : ";
    cin>>s1;
    cout<<"Enter the string2 : ";
    cin>>s2;
    int n = s1.length();
    int m = s2.length();
    cout<<"Solving using recursion : "<<usingRecursion(s1, s2, n, m)<<endl;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout<<"Solving using memoisation : "<<usingMemoisation(s1, s2, n, m, dp)<<endl;
    dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    cout<<"Solving using DP : "<<usingDP(s1, s2, n, m, dp)<<endl;
    return 0;
}