// Write a C++ program to print the permutation of a given string with spaces.

#include<bits/stdc++.h>
using namespace std;

void permutationOfString(string s, int i, int n, string helperStr){
    if(i >= n){
        cout<<helperStr<<endl;
        return;
    }
    else{
        permutationOfString(s, i+1, n, helperStr + "_" + s[i]);
        permutationOfString(s, i+1, n, helperStr + s[i]);
    }
    return;
}

int main(){

    string s;
    cout<<"Enter the string :";
    cin>>s;
    string helperStr = "";
    permutationOfString(s, 1, s.length(), helperStr + s[0]);

    return 0;
}