// Write a C++ program to print the Longest Common Prefix of given strings

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs, int n){
    if(n == 1) return strs[0];
    for(int i = 0; i < strs[0].length(); i++){
        for(int j = 1; j < n; j++){
            if((strs[j][i] != strs[0][i]) || (i >= strs[j].length())) return strs[0].substr(0, i);
        }
    }

    return strs[0];
}


int main(){

    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    if(!n) return 0;
    
    vector<string> strs(n);
    cout<<"Enter the input strings : ";
    for(int i=0; i<n; i++) cin>>strs[i];

    cout<<"Longest common prefix of the given strings is : "<<longestCommonPrefix(strs, n)<<endl;
    return 0;
}