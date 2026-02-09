// Write a C++ program to convert Roman to Integer

#include<bits/stdc++.h>
using namespace std;

int romanToInteger(string s){
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int res = 0;
    int n = s.length();
    int i = n-1;

    while(i >= 0){
        if((i < n-1) && (mp[s[i+1]] > mp[s[i]])){
            res = res - mp[s[i]];
        }else res = res + mp[s[i]];
        i--;
    }

    return res;
}

int main(){

    string s;
    cout<<"Enter a valid Roman string : ";
    cin>>s;

    cout<<"The integer value of the given Roman string is : "<<romanToInteger(s)<<endl;
    return 0;
}