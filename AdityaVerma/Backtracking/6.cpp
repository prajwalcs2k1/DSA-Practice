// Write a C++ program to solve Palindrome Partition problem

/*
    Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
    Example 1:
        Input: s = "aab"
        Output: [["a","a","b"],["aa","b"]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string str){
        int l, r;
        l = 0, r = str.length()-1;
        while(l <= r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void solve(string s, int index, int n, vector<vector<string>> &res, vector<string> aux){
        if(index >= n){
            res.push_back(aux);
            return;
        }
        string curr = "";
        for(int i=index; i<n; i++){
            curr += s[i];
            if(isPalindrome(curr)){
                aux.push_back(curr);
                solve(s, i+1, n, res, aux);
                aux.pop_back();
            }
        }

        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> aux;
        solve(s, 0, s.length(), res, aux);

        return res;
    }
};

void displayParitions(vector<vector<string>> &res){
    cout << "[\n";
    for(auto &vec : res){
        cout << "  [";
        for(int i = 0; i < vec.size(); i++){
            cout << "'" << vec[i] << "'";
            if(i != vec.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;
    
    Solution palindromePartition;

    vector<vector<string>> res = palindromePartition.partition(s);
    displayParitions(res);

    return 0;
}