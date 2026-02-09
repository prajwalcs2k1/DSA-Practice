// Write a C++ program to Remove Outermost Parentheses

#include<bits/stdc++.h>
using namespace std;

string processedString(string s){
    string str = "";
    if(s.length() == 0) return str;

    int openParenth = 0;

    int i=0, n = s.length();
    while(i < n){
        if(s[i] == '('){
            if(openParenth > 0){
                str += s[i];
            }
            openParenth++;
        }else{
            if(openParenth > 1){
                str += s[i];
            }
            openParenth--;
        }
        i++;
    }

    return str;
}

int main(){

    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"Output : "<<processedString(s)<<endl;
    return 0;
}