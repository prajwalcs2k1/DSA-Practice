// Write a C++ program to print all the permutations of an input string. ( No duplicate characters )


#include<bits/stdc++.h>
using namespace std;


// T.C. of the below code if O(n*n!), string printing takes O(n)
/*
    void swappingMethod(sting s, int index, int n){
        if(index >= n){
            cout<<s<<endl;
            return;
        }

        for(int i=index; i<n; i++){
            swap(s[i], s[index]);
            swappingMethod(s, index+1, n);
            swap(s[i], s[index]);
        }

        return;
    }
*/

// T.C. of the below code is O(n^2  *  n!) because substr takes O(n) and string concatenation also takes O(n) & string printing takes O(n)
void usingRecursion(string s, string res){
    if(s.length() == 0){
        cout<<res<<endl;
        return;
    }
    for(int j=0; j < s.length(); j++){
        usingRecursion(s.substr(0,j) + s.substr(j+1), res + s[j]);
    }

    return ;
}

// T.C. of the below code is O(n^2  *  n!) because substr takes O(n) and string concatenation also takes O(n) & string printing takes O(n)
void usingBacktracking(string s, string res){
    if(s.length() == 0){
        cout<<res<<endl;
        return;
    }
    for(int j=0; j < s.length(); j++){
        res = res + s[j];
        usingBacktracking(s.substr(0,j) + s.substr(j+1), res);
        res.pop_back();  // backtrack
        // res = res.substr(0,res.length()-1);
    }

    return ;
}

int main(){

    string s;
    cout<<"Enter the input string : ";
    cin>>s;

    cout<<"Permutations of "<<s<<" are (Using Recursion) :\n";
    usingRecursion(s, "");
    cout<<"Permutations of "<<s<<" are (Using Backtracking) :\n";
    usingBacktracking(s, "");
    return 0;
}