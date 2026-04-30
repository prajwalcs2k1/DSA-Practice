// Write a C++ program to print the permutation of a given string with case change. ( Input may include digits )

#include<bits/stdc++.h>
using namespace std;

void permutationOfStringWithCaseChange(string s, int i, int n, string hlpr){
    if(i >= n){
        cout<<hlpr<<endl;
        return;
    }

    if((s[i] >= '0') && (s[i] <= '9')) permutationOfStringWithCaseChange(s, i+1, n, hlpr + s[i]);
    else{
        permutationOfStringWithCaseChange(s, i+1, n, hlpr + s[i]);
        if((s[i] >= 'a') && (s[i] <= 'z')){
            permutationOfStringWithCaseChange(s, i+1, n, hlpr + char(s[i] - ('a' - 'A')));
        }else{
            permutationOfStringWithCaseChange(s, i+1, n, hlpr + char(s[i] + ('a' - 'A')));
        }
    }

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