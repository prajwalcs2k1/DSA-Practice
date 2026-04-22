// Given 2 strings s & t, write a C++ programs to count the occurences of anagrams of t in s

#include<bits/stdc++.h>
using namespace std;

void fetchAnagrams(string str, unordered_set<string>&res, int l){
    if(l == str.length()) {
        res.insert(str);
        return;
    }

    for(int i=l; i<str.length(); i++){
        swap(str[i], str[l]);
        fetchAnagrams(str, res, l+1);
        swap(str[i], str[l]);
    }

    return;
}

int bruteForce(string s, string t){
    int n,m;
    n = s.length();
    m = t.length();
    unordered_set<string> anagrams;
    fetchAnagrams(t, anagrams, 0);

    int count = 0;

    for(int i=0; i<=(n-m); i++){
        if(anagrams.count(s.substr(i, m))) count++;
    }

    return count;
}

int optimisedApp(string s, string t){
    int n,m,ans,required;

    n = s.length();          // Length of main string 's'
    m = t.length();          // Length of pattern string 't'

    ans = 0;                 // Stores total count of anagram occurrences

    unordered_map<char, int> mp;

    // Build frequency map of characters in 't'
    // mp[c] = how many times character 'c' is needed
    for(char c : t) mp[c]++;

    required = m;  
    // Total number of characters we still need to match
    // When required == 0 → current window is a valid anagram

    int left, right;
    left = right = 0;        // Sliding window boundaries

    // Start expanding the window using 'right'
    for(; right<n; right++){

        // If current character is still needed (mp > 0),
        // we are satisfying part of the requirement
        if(mp[s[right]] > 0){
            required--;      // One required character matched
        }

        // Decrease frequency of current character
        // Even if it's not needed, we still decrement
        // → helps track extra/unwanted characters (negative values)
        mp[s[right]]--;

        // If window size exceeds 'm', shrink from left
        if((right - left + 1) > m){

            // Before removing s[left], check:
            // If mp[s[left]] >= 0 → this character was contributing
            // to a valid match, so removing it breaks the match
            if(mp[s[left]] >= 0){
                required++;  // We now need one more character again
            }

            // Restore the frequency since we are removing it from window
            mp[s[left]]++;

            left++;         // Move left boundary forward
        }

        // If all required characters are matched
        // → current window is an anagram of 't'
        if(required == 0) ans++;
    }

    return ans;              // Return total count of anagram substrings
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
    cout<<optimisedApp(s, t)<<endl;
    return 0;
}