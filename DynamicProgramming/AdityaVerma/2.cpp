// Write a C++ program to find the subset sum which matches a given integer

#include<bits/stdc++.h>
using namespace std;

bool usingRecursion(int * arr, int sum, int n){
    if(sum == 0) return true;
    if((n <= 0) || (sum < 0)) return false;
    return usingRecursion(arr, sum, n-1) || usingRecursion(arr, sum-arr[n-1], n-1);
}

bool usingMemoization(int * arr, int sum, int n, vector<vector<int>> &dp){
    if(sum == 0) return true;
    if((n <= 0) || (sum < 0)) return false;
    if(dp[n][sum] != -1) return dp[n][sum];

    dp[n][sum] = usingMemoization(arr, sum, n-1, dp) || usingMemoization(arr, sum - arr[n-1], n-1, dp);
    return dp[n][sum];
}

bool usingDP(int * arr, int sum, int n, vector<vector<int>> &dp){
    // Base initialization
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    int N, n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int t;
    cout<<"Enter the number of tests : ";
    cin>>t;
    while(t--){
        cout<<"Enter the sum : ";
        cin>>N;
        if(!N){
            cout<<"Invalid sum provided!!\n";
            continue;
        }
        cout<<"Solving using recursion : "<<(usingRecursion(arr, N, n) ? "Sum found\n" : "Not found!!\n");
        vector<vector<int>> dp(n+1, vector<int>(N+1, -1));
        cout<<"Solving using memoisation : "<<(usingMemoization(arr, N, n, dp) ? "Sum found\n" : "Not found!!\n");
        dp = vector<vector<int>>(n+1, vector<int>(N+1, 0));
        cout<<"Solving using iterative DP : "<<(usingDP(arr, N, n, dp) ? "Sum found\n" : "Not found!!\n");
    }

    return 0;
}