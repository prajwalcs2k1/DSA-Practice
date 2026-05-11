// Write a C++ program to solve Word Break problem

/*
    Below is implemented using pure recursion + backtracking, this code will not optimally (will throw TLE) work for all test cases.
    To optimise the solution use DP.
*/

#include<bits/stdc++.h>
using namespace std;


bool wordBreakHelper(string s, set<string> &st, int longDictWord, int index, int n){
    if(index >= n) return true;
    string currStr = "";
    for(int i=index; i<n; i++){
        currStr = currStr + s[i];
        if(currStr.length() > longDictWord) return false;
        if(st.find(currStr) != st.end()){
            if(wordBreakHelper(s, st, longDictWord, i+1, n)) return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict){
    set<string> st;
    int longDictWord = INT_MIN;
    for(string str : wordDict){
        st.insert(str);
        if(str.length() > longDictWord) longDictWord = str.length();
    }

    return wordBreakHelper(s, st, longDictWord, 0, s.length());
}

int main(){
    string s = "applepenapple";

    vector<string> wordDict = {
        "apple","pen"
    };
    cout<<wordBreak(s, wordDict)<<endl;
    return 0;
}