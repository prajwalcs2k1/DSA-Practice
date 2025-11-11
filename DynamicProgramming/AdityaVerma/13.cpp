// Write a C++ program to print the length of the shortest common supersequence of given 2 strings

#include<bits/stdc++.h>
using namespace std;

int LCSusingDP(string s1, string s2, int n, int m, vector<vector<int>> &dp){

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

    string s1, s2;
    cout<<"Enter the string 1 : ";
    cin>>s1;
    cout<<"Enter the string 2 : ";
    cin>>s2;

    int n = s1.length();
    int m = s2.length();

    int LCS = 0;
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    LCS = LCSusingDP(s1, s2, n, m, dp);
    cout<<"Length of the shortest common super-sequence is : "<<(n+m-LCS)<<endl;
    return 0;
}