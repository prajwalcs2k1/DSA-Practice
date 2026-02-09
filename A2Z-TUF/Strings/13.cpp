// Write a C++ program to print the Longest Palindrome Substring

#include<bits/stdc++.h>
using namespace std;

string LPSHelper(string s, int left, int right, int n){
    while((left >= 0) && (right < n) && (s[left] == s[right])){
        left--;
        right++;
    }

    return s.substr(left + 1, right - left - 1);
}

string LPS(string s){
    int n = s.length();

    string ans;

    for(int i=0; i<n; i++){
        string res1 = LPSHelper(s, i, i, n);        // for Odd length
        string res2 = LPSHelper(s, i, i+1, n);      // for Even length

        ans = ans.length() > ((res1.length() > res2.length()) ? res1.length() : res2.length()) ? ans : ((res1.length() > res2.length()) ? res1 : res2);
    }

    return ans;
}

int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;

    cout<<"Longest Palindrome Substring is : "<<LPS(s)<<endl;

    return 0;
}