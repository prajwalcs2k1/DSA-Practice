/*
    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
*/

#include<bits/stdc++.h>
using namespace std;

string bruteForce(string s, string t){
    int n = s.length(), m = t.length();
    string ans = "";
    int minLen = INT_MAX;
    unordered_map<char, int> mp, aux;
    for(char c : t) mp[c]++;
    aux = mp;
    for(int i=0; i<n; i++){
        int j = i;
        mp = aux;
        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) mp.erase(s[j]);
            }
            if(mp.empty()){
                if((j-i+1) < minLen) {
                    minLen = j-i+1;
                    ans = s.substr(i, minLen);
                }
                break;
            }
            j++;
        }
    }


    return ans;
}

string optimisedApp(string s, string t){
    int n = s.length(), m = t.length();
    if(m > n) return "";

    unordered_map<char, int> mp;

    // Build frequency map
    for(char c : t) mp[c]++;

    int required = m;
    int left = 0;

    int mnSubLen = INT_MAX, st = 0;

    for(int right = 0; right < n; right++){

        // Always decrement
        if(mp[s[right]] > 0){
            required--;
        }
        mp[s[right]]--;

        // Shrink window when valid
        while(required == 0){

            if(right - left + 1 < mnSubLen){
                mnSubLen = right - left + 1;
                st = left;
            }

            // Always increment back
            mp[s[left]]++;
            
            // if s[left] character is not present string t, then s[left] never becomes greater than 0
            if(mp[s[left]] > 0){
                required++;
            }

            left++;
        }
    }

    if(mnSubLen == INT_MAX) return "";

    return s.substr(st, mnSubLen);
}

int main(){
    string s,t;
    cout<<"Enter the strings :";
    cin>>s>>t;
    cout<<bruteForce(s, t)<<endl;
    cout<<optimisedApp(s, t)<<endl;
    return 0;
}