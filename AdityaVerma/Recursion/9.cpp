// Write a C++ program to print the permutation of a given string with case change.

#include<bits/stdc++.h>
using namespace std;

void permutationOfStringWithCaseChange(string s, int i, int n, string helperStr){
    if(i>=n){
        cout<<helperStr<<endl;
        return;
    }
    permutationOfStringWithCaseChange(s, i+1, n, helperStr + s[i]);
    permutationOfStringWithCaseChange(s, i+1, n, helperStr + char(s[i] - ('a' - 'A')));
    return;
}

int main(){

    string s;
    cout<<"Enter the string :";
    cin>>s;
    string helperStr = "";
    permutationOfStringWithCaseChange(s, 0, s.length(), helperStr);

    return 0;
}