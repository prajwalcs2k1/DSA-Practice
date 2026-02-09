// Write a C++ program to convert String to Integer (atoi)

/*
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

    The algorithm for myAtoi(string s) is as follows:
        Whitespace: Ignore any leading whitespace (" ").
        Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
        Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
        Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
        
    Return the integer as the final result.
*/

#include<bits/stdc++.h>
using namespace std;

void removeLeadingSpaces(string &s){
    int n = s.length();
    int i = 0;
    while((i < n) && (s[i] == ' ')) i++;
    if(i >= n) return;
    s.erase(0, i);
    return;
}

int lstDgtIdx(string s, int i){
    int n = s.length();
    while((i < n) && ((s[i] >= '0') && (s[i] <= '9'))) i++;
    return i-1;
}

int stringToNum(string s, int lastDigitIndex, bool positive){
    long long int sum = 0;
    int i = 0;
    while(i <= lastDigitIndex){
        sum = sum * 10 + (s[i] - '0');
        if(sum > INT_MAX){
            if(positive) return INT_MAX;
            return INT_MIN;
        }
        i++;
    }
    return positive?sum:sum*-1;
}

int myAtoi(string s) {
    removeLeadingSpaces(s);
    if(s.length() == 0) return 0;
    bool positive = true;
    if(s[0] == '-') positive = false;
    if((s[0] == '-') || (s[0] == '+')) s.erase(0, 1);
    int lastDigitIndex = lstDgtIdx(s, 0);
    return stringToNum(s, lastDigitIndex, positive);
}

int main(){
    
    string s;
    cout<<"Enter the string : ";
    getline(cin, s);

    cout<<"Integer is : "<<myAtoi(s)<<endl;

    return 0;
}