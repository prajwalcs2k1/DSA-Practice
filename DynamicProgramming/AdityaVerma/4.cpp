// Write a C++ program to print the no. of subsets with the given sum

#include<bits/stdc++.h>
using namespace std;

void usingRecursion(vector<int> &arr, int n, int sum, int &count){
    if(sum == 0){
        count++;
        return;
    }
    if(n <= 0) return;
    if(arr[n-1] <= sum){
        usingRecursion(arr, n-1, sum - arr[n-1], count);
    }

    usingRecursion(arr, n-1, sum, count);
    return;
}

int usingMemoization(vector<int> &arr, int n, int sum, vector<vector<int>> &dp){
    if(sum == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(dp[n][sum] != -1) return dp[n][sum];

    int include = 0, exclude = 0;
    if(arr[n-1] <= sum){
        include = usingMemoization(arr, n-1, sum - arr[n-1], dp);
    }
    exclude = usingMemoization(arr, n-1, sum, dp);
    
    return dp[n][sum] = include + exclude;
}

int usingDp(vector<int> &arr, int n, int sum, vector<vector<int>> &dp){
    for(int i=0; i<sum+1; i++) dp[0][i] = 0;
    for(int i=0; i<n+1; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int n, sum;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int t;
    cout<<"Enter no. of tests : ";
    cin>>t;
    while(t--){
        int count = 0;
        cout<<"Enter the sum : ";
        cin>>sum;
        usingRecursion(arr, n, sum, count);
        cout<<"Solving using recursion : "<<count<<"\n";
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

        count = usingMemoization(arr, n, sum, dp);
        cout<<"Solving using memoization : "<<count<<"\n";

        dp = vector<vector<int>>(n+1, vector<int>(sum+1, 0));
        count = usingDp(arr, n, sum, dp);
        cout<<"Solving using DP : "<<count<<"\n";
    }

    return 0;
}