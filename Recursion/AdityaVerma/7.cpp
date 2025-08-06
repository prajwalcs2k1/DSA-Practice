// Write a C++ program to print unique subsets of a string with duplicate characters

#include<bits/stdc++.h>
using namespace std;

/*
    void bruteForce(string s, int i, string helper, unordered_map<string, int>& mp){
        if(i == s.length()){
            if(mp.count(helper) == 0){
                mp[helper]++;
                cout<<helper<<endl;
            }
            return;
        }
        bruteForce(s, i+1, helper, mp);
        helper += s[i];
        bruteForce(s, i+1, helper, mp);
        return;
    }
*/

void bruteForce(string s, int index, string helper, unordered_map<string, int>& mp){
    if(mp.count(helper) == 0) {
        mp[helper]++;
        cout<<helper<<endl;
    }
    for(int i=index; i<s.length(); i++){
        bruteForce(s, i+1, helper + s[i], mp);
    }
    return;
}

void optimisedApp(string s, int index, string helper){
    cout<<helper<<endl;
    for(int i=index; i<s.length(); i++){
        if((i>index) && (s[i] == s[i-1])) continue;
        optimisedApp(s, i+1, helper + s[i]);
    }
    return;
}

int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;
    unordered_map<string, int> mp;
    sort(s.begin(), s.end());
    cout<<"Bruteforce solution :-\n";
    bruteForce(s, 0, "", mp);
    cout<<"Optimised solution :-\n";
    optimisedApp(s, 0, "");

    return 0;
}