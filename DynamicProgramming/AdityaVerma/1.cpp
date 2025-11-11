// Write a C++ program to solve 0/1 KnapSack problem

#include<bits/stdc++.h>
using namespace std;

void recursionHelper(vector<int> & weights, vector<int>  & value, int n, int W, int &ans, int temp, int i){
    if( (i >= n) || (W <= 0)){
        if(temp > ans) ans = temp;
        return;
    }
    recursionHelper(weights, value, n, W, ans, temp, i+1);
    if((W-weights[i]) >= 0) recursionHelper(weights, value, n, W-weights[i], ans, temp+value[i], i+1);
    return;
}

int usingRecursion(vector<int> & weights, vector<int>  & value, int n, int W){
    int ans = 0, temp = 0;
    recursionHelper(weights, value, n, W, ans, temp, 0);
    return ans;
}

int usingMemoization(vector<int> & weights, vector<int>  & value, int n, int W, vector<vector<int>> & dp){
    if((n < 0) || (W <= 0)){
        return 0;
    }

    if(dp[n][W] != -1) return dp[n][W];

    if(W < weights[n]) {
        dp[n][W] = usingMemoization(weights, value, n-1, W, dp);
    }
    else{
        dp[n][W] = max((value[n] + usingMemoization(weights, value, n-1, W-weights[n], dp)) , usingMemoization(weights, value, n-1, W, dp));
    }
    
    return dp[n][W];
}

int usingDP(vector<int> &weights, vector<int> &values, int n, int W, vector<vector<int>> &dp){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(j >= weights[i-1]){
                dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main(){

    int n, W;
    cout<<"Enter the size of (weights & value) arrays : ";
    cin>>n;
    vector<int> weights(n);
    vector<int> value(n);
    cout<<"Enter the weights of items : ";
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }
    cout<<"Enter the value of items : ";
    for(int i=0; i<n; i++){
        cin>>value[i];
    }
    int t;
    cout<<"Enter the no. of tests : ";
    cin>>t;
    while(t--){
        cout<<"Enter the knapsack capacity : ";
        cin>>W;
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        cout<<"Solution using Recursion : "<<usingRecursion(weights, value, n, W)<<endl;
        cout<<"Solution using Memoization : "<<usingMemoization(weights, value, n-1, W, dp)<<endl;
        dp = vector<vector<int>>(n+1, vector<int>(W+1, 0));
        cout<<"Solution using iterative DP : "<<usingDP(weights, value, n, W, dp)<<endl;
    }    
    return 0;
}