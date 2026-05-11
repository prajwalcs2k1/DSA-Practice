// Wtite a C++ program to Print N Digit numbers with digits in increasing order

/*
    Given an integer n, print all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. of the below code is 9^N

void solve(int N, vector<int> &res, int lastDigit, int number){
    if(N == 0){
        res.push_back(number);
        return;
    }

    for(int i = lastDigit + 1; i<=9; i++){
        solve(N-1, res, i, number * 10 + i);
    }

    return;
}

void displayVector(vector<int> res){

    for(int ele : res) cout<<ele<<" ";
    cout<<endl;

    return;
}

int main(){
    int N;
    cout<<"Enter the value of N : ";
    cin>>N;

    vector<int> res;
    if(N == 1) res.push_back(0);

    solve(N, res, 0, 0);
    displayVector(res);
    return 0;
}