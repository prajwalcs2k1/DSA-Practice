/* 
    You're given a string s, where each character represents a different toy type. You can only pick at most 2 different types of toys. Your task is to find the length of the longest substring in which there are at most 2 distinct characters.
*/

#include<bits/stdc++.h>
using namespace std;


pair<int, int> bruteForce(string s, int K){
    int mx = 0;
    int n = s.length();
    int st, en;
    st=en=-1;
    for(int i=0; i<n; i++){
        unordered_map<char, int>mp;
        for(int j=i; j<n; j++){
            mp[s[j]]++;
            if(mp.size() > K) break;
            if(mx < (j-i+1)){
                mx = j-i+1;
                st = i;
                en = j;
            }
        }
    }
    return make_pair(st, en);
}

pair<int, int> optimisedApp(string s, int K){
    int n = s.length();
    int mx = 0;
    int i,j,st,en;
    i=j=0;
    st=en=-1;
    unordered_map<char, int> mp;

    while(j<n){
        mp[s[j]]++;
        while(mp.size() > K){
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }
        if(mx < (j-i+1)){
            mx = j-i+1;
            st = i;
            en = j;
        }
        j++;
    }

    return {st, en};
}

int main(){

    string s;
    cout<<"Enter the string :";
    cin>>s;
    if(!s.length()){
        cout<<"String length cannot be 0!!\n";
        return 0;
    }
    int K;
    cout<<"Enter the number of distinct toys user can select :";
    cin>>K;
    if(K<=0){
        cout<<"Invalid toy size provided!!\n";
        return 0;
    }
    pair<int, int>p;
    p = bruteForce(s, K);
    if((p.first == -1) || (p.second == -1)){
        cout<<"Valid answer does not exist"<<endl;
        return 0;
    }
    cout<<"Longest substring with atmost "<<K<<" toys is :";
    for(int i=p.first; i<=p.second; i++) cout<<s[i];
    cout<<"\n";

    p = optimisedApp(s, K);
    if((p.first == -1) || (p.second == -1)){
        cout<<"Valid answer does not exist"<<endl;
        return 0;
    }
    cout<<"Longest substring with atmost "<<K<<" toys is :";
    for(int i=p.first; i<=p.second; i++) cout<<s[i];
    cout<<"\n";

    return 0;
}