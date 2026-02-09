// Write a C++ program to Rotate String

/*
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
    A shift on s consists of moving the leftmost character of s to the rightmost position.
*/

#include<bits/stdc++.h>
using namespace std;

string bruteForce(string s, string goal){
    if(s.length() != goal.length()) return "false";
    if(s == goal) return "true";

    int n = s.length();
    while(n){
        char ch = s[0];
        s.erase(0, 1);      // O(n)
        s = s + ch;
        if(s == goal) return "true";    // O(n)
        n--;
    }

    return "false";
}

string optimised(string s, string goal){
    if(s.length() != goal.length()) return "false";
    if(s == goal) return "true";
    
    string hlp = s + s;
    if(hlp.find(goal) != string::npos) return "true";

    return "false";
}

int main(){

    string s, goal;
    cout<<"Enter the input strings : ";
    cin>>s>>goal;

    cout<<"Is "<<s<<" rotateble to form "<<goal<<" ? "<<bruteForce(s, goal)<<endl;
    cout<<"Is "<<s<<" rotateble to form "<<goal<<" ? "<<optimised(s, goal)<<endl;

    return 0;
}