// Write a C++ program to print all the permutations of an input string. ( Duplicate characters may exist )


#include<bits/stdc++.h>
using namespace std;

void usingRecursion(string s, string res){
    if(s.length() == 0){
        cout<<res<<endl;
        return;
    }
    bool duplicates[26] = {false};
    for(int j=0; j < s.length(); j++){
        if(duplicates[s[j] - 'a']) continue;
        usingRecursion(s.substr(0,j) + s.substr(j+1), res + s[j]);
        duplicates[s[j] - 'a'] = true;
    }
    return ;
}

void usingBacktracking(string s, string res){
    if(s.length() == 0) {
        cout<<res<<endl;
        return;
    }

    bool duplicates[26] = {false};
    for(int i=0; i<s.length(); i++){
        if(duplicates[s[i] - 'a']) continue;
        res = res + s[i];
        usingBacktracking(s.substr(0, i) + s.substr(i+1), res);
        res.pop_back(); // backtrack
        duplicates[s[i] - 'a'] = true;
    }
    return;
}

void usingSwapping(string s, int index){
    if(index == s.length()){
        cout<<s<<endl;
        return;
    }

    for(int i=index; i<s.length(); i++){
        if((index != i) && (s[index] == s[i])) continue;
        swap(s[index], s[i]);
        usingSwapping(s, index+1);
        swap(s[index], s[i]); //backtrack
    }

    return;
}


int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;

    cout<<"Permutations of "<<s<<" are (Using Recursion) :\n";
    usingRecursion(s, "");
    cout<<"Permutations of "<<s<<" are (Using Backtracking) :\n";
    usingBacktracking(s, "");
    cout<<"Permutations of "<<s<<" are (Using Swapping) : \n";
    usingSwapping(s, 0);

    return 0;
}