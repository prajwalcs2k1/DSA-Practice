// Write a C++ program to Sort Characters by Frequency

/*
    Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
    Return the sorted string. If there are multiple answers, return any of them.
*/

#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s){
    int n = s.length();
    string ans;
    ans.reserve(n);
    unordered_map<char, int> mp;
    vector<vector<char>> bucket(n+1);
    
    for (char c : s){
        mp[c]++;
    }
    
    for(auto it : mp){
        bucket[it.second].push_back(it.first); 
    }

    for(int freq = n; freq > 0; freq--){
        if(bucket[freq].size() != 0){
            for(char c : bucket[freq]) ans.append(freq, c);
        }
    }

    return ans;
}

int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;

    cout<<"String after sorting character wise : "<<frequencySort(s)<<endl;

    return 0;
}