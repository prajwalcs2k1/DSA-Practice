// Write a C++ program to check if 2 input strings are anagram of each other

/*
    Anagram:- An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
*/

#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){

    int n = s.length();
    int i = 0;
    unordered_map<char, int> mp;
    while(i < n) mp[s[i++]]++;

    i = 0;

    while(i < n){
        if(mp.find(t[i]) == mp.end()) return false;
        mp[t[i]]--;
        if(mp[t[i]] < 0) return false;
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

    cout<<"Are the input strings anagram of each other ? "<<(isAnagram(s, t) ? "true" : "false")<<endl;

    return 0;
}