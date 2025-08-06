// Write a C++ program to find the pattern t in text s which contains only characters

#include<bits/stdc++.h>
using namespace std;


bool KMP(string text, string patt, vector<int>&lps){
    int m = text.length();
    int n = patt.length();
    int i,j;
    i=j=0;
    while((i<m) && (j<n)){
        if(text[i] == patt[j]){
            j++;
        }
        else{            
            j = lps[j-1];
        }
        i++;
    }
    return j >= n;
}

vector<int> LPS(string patt, int n){
    vector<int> res(n,0);
    int i,len;
    i=1,len=0;
    while(i < n){
        if(patt[i] == patt[len]){
            len++;
            res[i] = len;
            i++;
        }else{
            if(len == 0){
                res[i] = 0;
                i++;
            }
            else{
                len = res[len-1];
            }
        }
    }
    return res;
}

int main(){
    string text, patt;
    cout<<"Enter the text & pattern strings :";
    cin>>text>>patt;
    if(!text.length() || !patt.length()){
        cout<<"Strings cannot be empty!!\n";
        return 0;
    }
    vector<int> lps = LPS(patt, patt.length());
    // for(auto it : lps) cout<<it<<" ";
    cout<<KMP(text, patt, lps);
    return 0;
}