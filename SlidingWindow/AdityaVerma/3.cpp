// Given 2 strings s & t, write a C++ programs to count the occurences of anagrams of t in s

#include<bits/stdc++.h>
using namespace std;

void fetchAnagrams(string str, vector<string>&res, int j, int m, string helperStr){
    if(j >= m) {
        res.push_back(helperStr);
        return;
    }
    for(int i=0; i<m; i++){
        if(i==j) continue;
        helperStr = helperStr + 
    }
}

int bruteForce(string s, string t){
    int n,m;
    n = s.length();
    m = t.length();
    vector<string> anagrams;
    string helperStr = t[0];
    fetchAnagrams(t, anagrams, 0, m, helperStr);
}

int main(){
    string s,t;
    cout<<"Enter the strings :";
    cin>>s>>t;
    if(t.length() > s.length()){
        cout<<"Invalid strings provided!!\n";
        return 0;
    }
    cout<<bruteForce(s, t)<<endl;
    return 0;
}