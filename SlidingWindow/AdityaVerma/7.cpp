// Write a C++ program to print the longest substring without repeating characters

#include<bits/stdc++.h>
using namespace std;

pair<int, int> bruteForce(string s){
    int mx = 0;
    int st,en;
    int n = s.length();
    st=en=-1;
    for(int i=0; i<n; i++){
        unordered_map<char, int> mp;
        int j=i;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]] > 1){      
                break;
            }
            if(mx < (j-i+1)){
                mx = j-i+1;
                en = j;
                st = i;
            }    
            j++;
        }
    }
    return {st, en};
}

pair<int, int> optimisedApp(string s){
    int st,en;
    st=en=-1;
    int mx = 0;
    int i,j;
    i=j=0;
    int n = s.length();
    unordered_map<char, int> mp;
    while((i<=j) && (j<n)){
        mp[s[j]]++;
        while(mp[s[j]] > 1){
            mp[s[i]]--;
            i++;
        }
        if(mx < (j-i+1)){
            mx = j-i+1;
            en = j;
            st = i;
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
        cout<<"String cannot be empty!!\n";
        return 0;
    }

    pair<int, int> p;
    p = bruteForce(s);
    if((p.first == -1) || (p.second == -1)){
        cout<<"Not Found\n";
        return 0;
    }
    for(int i=p.first; i<=p.second; i++){
        cout<<s[i];
    }
    cout<<"\n";

    p = optimisedApp(s);
    if((p.first == -1) || (p.second == -1)){
        cout<<"Not Found\n";
        return 0;
    }
    for(int i=p.first; i<=p.second; i++){
        cout<<s[i];
    }
    cout<<"\n";

    return 0;
}