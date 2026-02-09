// Write a C++ program to find the Sum of Beauty of All Substrings

/*
    The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

    For example, the beauty of "abaacc" is 3 - 1 = 2.
    Given a string s, return the sum of beauty of all of its substrings.
*/


#include<bits/stdc++.h>
using namespace std;

int sumOfBeauty(string s){
    int n = s.length();
    int ans = 0;

    for(int i=0; i<n; i++){
        int freq[26] = {0};
        for(int j=i; j<n; j++){
            freq[s[j] - 'a']++;
            int mx = 0, mn = INT_MAX;
            for(int k=0; k<26; k++){
                if(freq[k] > 0){
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
            }

            ans = ans + mx - mn;
        }
    }

    return ans;
}

int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;

    cout<<"Sum of Beauty of all substrings is : "<<sumOfBeauty(s)<<endl;

    return 0;
}