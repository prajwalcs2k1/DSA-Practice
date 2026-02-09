// Write a C++ program to find the Maximum Nesting Depth of the Parentheses

/*
    Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
*/

#include<bits/stdc++.h>
using namespace std;

int mxDepthParen(string s){
    int openParenthesis = 0;
    int mxDepth = 0;
    int n = s.length();

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            openParenthesis++;
            mxDepth = max(mxDepth, openParenthesis);
        }else if(s[i] == ')') openParenthesis--;
        else continue;
    }

    return mxDepth;
}

int mxDepthBrute(string s) {
    int n = s.length();
    int maxDepth = 0;

    for (int i = 0; i < n; i++) {
        int open = 0, close = 0;

        for (int j = 0; j <= i; j++) {
            if (s[j] == '(') open++;
            else if (s[j] == ')') close++;
        }

        maxDepth = max(maxDepth, open - close);
    }

    return maxDepth;
}


int main(){

    string s;
    cout<<"Enter the valid parenthesis string : ";
    cin>>s;

    cout<<"Max. nesting depth of the parenthesis is (optimised) : "<<mxDepthParen(s)<<endl;
    cout<<"Max. nesting depth of the parenthesis is (bruteForce) : "<<mxDepthBrute(s)<<endl;

    return 0;
}