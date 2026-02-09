// Write a C++ program to find the Largest Odd Number in String

#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string s){

    int n = s.length();
    int i, idx;
    i = n-1;

    while(i >= 0){
        int digit = s[i] - '0';
        if(digit % 2) return s.substr(0, i+1);
        i--;
    }

    return "";
}

int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;
    string answer = largestOddNumber(s);
    cout<<"Largest odd number in the input string is : "<<(answer.length() == 0 ? "NaN" : answer)<<endl;

    return 0;
}