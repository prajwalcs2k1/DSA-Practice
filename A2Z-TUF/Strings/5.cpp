// Write a C++ program to find if the input strings are Isomorphic

/*
    Given two strings s and t, determine if they are isomorphic.
        -   Two strings s and t are isomorphic if the characters in s can be replaced to get t.
        -   All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/

#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t){
    unordered_map<char, char> mp, mp2;
    int n = s.length();
    int i = 0;

    while(i < n){
        if(mp.find(s[i]) == mp.end()){
            if(mp2.find(t[i]) == mp2.end()){
                mp[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }else return false;
        }else if(mp[s[i]] != t[i]) return false;

        i++;
    }

    return true;
}

int main(){

    string s, t;
    cout<<"Enter the 2 input strings : ";
    getline(cin, s);
    getline(cin, t);
    if(s.length() != t.length()) return 0;

    cout<<"Are the given input strings Isomorphic ? "<<(isIsomorphic(s, t) ? "true" : "false")<<endl;

    return 0;
}