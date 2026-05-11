// Write a C++ program to print the Letter Combinations of a Phone Number

/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
    A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


    Example 1:
        Input: digits = "23"
        Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include<bits/stdc++.h>
using namespace std;

void letterCombinations(string phoneNumber, int index, int N, vector<string> &res, string currCombination, vector<string> &keypad){
    if(index >= N) {
        res.push_back(currCombination);
        return;
    }
    
    for(int i=0; i<keypad[phoneNumber[index] - '0'].length(); i++){
        char currChar = keypad[phoneNumber[index] - '0'][i];
        currCombination += currChar;
        letterCombinations(phoneNumber, index+1, N, res, currCombination, keypad);
        currCombination.pop_back();
    }

    return;
}

void displayOutput(vector<string> res){
    cout<<"Output:- [";
    for(string str : res) cout<<" '"<<str<<"', ";
    cout<<"]\n";

    return;
}

int main(){

    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string phoneNumber;
    cout<<"Enter the phone number : ";
    cin>>phoneNumber;

    vector<string> res;
    letterCombinations(phoneNumber, 0, phoneNumber.length(), res, "", keypad);

    displayOutput(res);

    return 0;
}