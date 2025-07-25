/*
    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
*/

#include<bits/stdc++.h>
using namespace std;

string bruteForce(string s, string t){
    int n,m;
    n = s.length();
    m = t.length();
    int mn = INT_MAX;
    string res = "";
    unordered_map<char, int> mp, aux;
    for(auto it : t) mp[it]++;
    aux = mp;
    int st, en;
    st = en = -1;
    for(int i=0; i<n; i++){
        aux = mp;
        int j=i;
        while((j<n) && (aux.size())){
            if(aux.find(s[j]) != aux.end()){
                aux[s[j]]--;
                if(aux[s[j]] == 0) aux.erase(s[j]);
            }
            j++;
        }
        if(aux.size() == 0){
            j--;
            if(mn > (j-i+1)){
                mn = j-i+1;
                st = i;
                en = j;
            }
        }
    }
    if((st == -1) || (en == -1)) return "";
    for(int i=st; i<=en; i++) res += s[i];
    return res;
}

string optimisedApp(string s, string t){
    int st, en;
    st=en=0;
    int n, m;
    n = s.length();
    m = t.length();
    if(n < m) return "";

    unordered_map<char, int> mp, aux;
    int needCount, have;
    string res = "";
    int resLen = INT_MAX;
    int resStart = 0;
    for(auto c : t) mp[c]++;
    needCount = mp.size();
    have = 0;

    while(en < n){
        char c = s[en];
        aux[c]++;
        if(mp.count(c) && (aux[c] == mp[c])) have++;

        while(have == needCount){
            if(resLen > (en - st + 1)){
                resLen = en - st + 1;
                resStart = st;
            }
            aux[s[st]]--;
            if(mp.count(s[st]) && aux[s[st]] < mp[s[st]]) have--;
            st++;
        }
        en++;
    }
    return resLen == INT_MAX ? "" : s.substr(resStart, resLen);
}

int main(){
    string s,t;
    cout<<"Enter the strings :";
    cin>>s>>t;
    cout<<bruteForce(s, t)<<endl;
    cout<<optimisedApp(s, t)<<endl;
    return 0;
}