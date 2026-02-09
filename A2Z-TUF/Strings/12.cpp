// Write a C++ program Count Number of Substrings

/*
    You are given a string s and a positive integer k. Return the number of substrings that contain exactly k distinct characters.
*/

#include<bits/stdc++.h>
using namespace std;

int atMost(string s, int k){
    int res = 0;
    unordered_map<char, int> mp;
    int n = s.length();
    int i = 0, j = 0;

    while(j < n){
        mp[s[j]]++;

        while(mp.size() > k){
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }

        res = res + j - i + 1;
        j++;
    }

    return res;
}

int main(){

    string s;
    int k;
    cout<<"Enter the input string : ";
    cin>>s;

    cout<<"Enter the K value : ";
    cin>>k;

    cout<<"No. of substrings with "<<k<<" distinct characters is : "<<atMost(s, k) - atMost(s, k-1)<<endl;

    return 0;
}