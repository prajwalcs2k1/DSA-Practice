// Write a C++ program to Print N-bit binary numbers having more 1s than 0s

/*
    Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.
*/

#include<bits/stdc++.h>
using namespace std;

void binaryStringGenerator(int i, int n, string hlpr, int zeroes, int ones, vector<string> &res){
    if(i == n){
        res.push_back(hlpr);
        return;
    }

    if(zeroes < ones){        
        binaryStringGenerator(i+1, n, hlpr + '1', zeroes, ones-1, res);
    }
    // Below oder is maintained to print the binary digits decreasing magnitude
    else{
        binaryStringGenerator(i+1, n, hlpr + '1', zeroes, ones-1, res);
        binaryStringGenerator(i+1, n, hlpr + '0', zeroes-1, ones, res);
    }

    return;
}

vector<string> NBitBinary(int n){
    if(n == 0) return {};
    if(n == 1) return {"1"};
    vector<string> res;
    string hlpr = "1";
    binaryStringGenerator(1, n, hlpr, n-1, n-1, res);
    return res;
}

void display(vector<string> &res){

    for(string s : res) cout<<s<<endl;
    return;
}

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    vector<string> res = NBitBinary(n);
    display(res);
    return 0;
}