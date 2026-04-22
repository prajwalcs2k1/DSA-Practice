// Write a C++ program to print the longest substring with K unique characters

#include<bits/stdc++.h>
using namespace std;

pair<int, int> bruteForce(string s, int K){
    int n = s.length();
    int mx = INT_MIN;
    int st,en;
    st=en=-1;
    for(int i=0; i<n; i++){
        int j = i;
        unordered_map<char, int> mp;
        while((mp.size() <= K) && (j < n)){
            mp[s[j]]++;
            if(mp.size() == K){
                if(mx < (j-i+1)){
                    mx = j-i+1;
                    en = j;
                    st = i;
                }
            }
            j++;
        }
    }
    return make_pair(st, en);
}

pair<int, int> optimisedApp(string s, int K){
    int mx = INT_MIN;
    int n = s.length();
    int i,j,st,en;
    i=j=0;
    st=en=-1;
    unordered_map<char, int> mp;
    while((i <= j) && (j < n)){
        mp[s[j]]++;
        while(mp.size() > K){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]--;
            }
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }
        if(mp.size() == K){
            if(mx < (j-i+1)){
                mx = j-i+1;
                st = i;
                en = j;
            }
        }

        j++;
    }

    return {st, en};
}


int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    if(s.length() == 0){
        cout<<"String cannot be empty!!"<<endl;
        return 0;
    }
    int K;
    cout<<"Enter the size of K: ";
    cin>>K;
    if((K == 0 )|| (K == s.length())){
        cout<<"K value is invalid!!"<<endl;
        return 0;
    }
    pair<int, int>p;
    p = bruteForce(s, K);
    if((p.first == -1) || (p.second == -1)){
        cout<<"Not Found!!\n";
        return 0;
    }
    for(int i=p.first; i<=p.second; i++) cout<<s[i];
    cout<<endl;

    p = optimisedApp(s, K);
    if((p.first == -1) || (p.second == -1)){
        cout<<"Not Found!!\n";
        return 0;
    }
    for(int i=p.first; i<=p.second; i++) cout<<s[i];
    cout<<endl;
    return 0;
}