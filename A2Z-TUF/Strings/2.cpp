// Write a C++ program to Reverse Words in a String

#include<bits/stdc++.h>
using namespace std;

void trim(string &S){
    int n = S.length() - 1;
    int i=0;
    while(S[i] == ' ') i++;
    S.erase(0, i);

    while(S[n] == ' ') n--;
    S.erase(n+1);

    return ;
}

void removeExtraSpaces(string &S){
    int n = S.length();
    int i, j;
    i = 0, j = 0;
    while(i < n){
        while((i<n) && (S[i] == ' ')) i++;

        while((i<n) && (S[i] != ' ')){
            S[j++] = S[i++];
        }

        S[j++] = ' ';
    }

    S.resize(j);

    return;
}

string reverseSentence(string S){
    reverse(S.begin(), S.end());

    int idx = 0;
    for(int i=0; i<S.length(); ){
        if(S[i] == ' '){
            reverse(S.begin() + idx, S.begin() + i);
            while((S[i] == ' ') && (i < S.length())) i++;
            idx = i;
        }else if(i == (S.length()-1)){
            reverse(S.begin() + idx, S.begin() + i + 1);
            i++;
        }else i++;
    }

    removeExtraSpaces(S);
    trim(S);

    return S;
}

int main(){

    string S;
    cout<<"Enter the sentence : ";
    getline(cin, S);

    cout<<"Sentence after reversing the words : "<<reverseSentence(S)<<endl;

    return 0;
}