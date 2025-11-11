// Write a C++ program to find the minimum no. of insertion & deletion needed to convert string A to sting B

#include<bits/stdc++.h>
using namespace std;

int usingMemoisation(string A, string B, int n, int m, vector<vector<int>> &dp){
    if(!n || !m) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    int ans = 0;
    if(A[n-1] == B[m-1]){
        ans = 1 + usingMemoisation(A, B, n-1, m-1, dp);
    }else{
        ans = max(usingMemoisation(A, B, n, m-1, dp) , usingMemoisation(A, B, n-1, m, dp));
    }

    dp[n][m] = ans;
    return dp[n][m];
}

int main(){
    string A, B;
    cout<<"Enter the string A : ";
    cin>>A;
    cout<<"Enter the string B : ";
    cin>>B;

    int n = A.length();
    int m = B.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int LCS = usingMemoisation(A, B, n, m, dp);
    cout<<"Min. no. of operations (insertion & deletion) to convert A to B is : "<<((n - LCS) + (m - LCS))<<endl;

    return 0;
}