// Write a C++ program to generate all balanced parenthesis 

#include<bits/stdc++.h>
using namespace std;

void balancedParenthesisUsingStack(int n, string hlpStr, stack<char> st){
    if(!n && st.empty()){
        cout<<hlpStr<<endl;
        return;
    }
    if(n){
        if(st.empty()){
            st.push('(');
            balancedParenthesisUsingStack(n-1, hlpStr + '(', st);
        }else{
            st.push('(');
            balancedParenthesisUsingStack(n-1, hlpStr + '(', st);
            st.pop();
            st.pop();
            balancedParenthesisUsingStack(n, hlpStr + ')', st);
        }
    }else{
        st.pop();
        balancedParenthesisUsingStack(n, hlpStr + ')', st);
    }
    return;
}

void balancedParenthesis(int n, string ans, int open, int close){
    if(!close && !open){
        cout<<ans<<endl;
        return;
    }
    if(open) balancedParenthesis(n, ans + '(', open-1, close);    
    if(close > open) balancedParenthesis(n, ans + ')', open, close-1);
    return;
}

int main(){
    int n;
    cout<<"Enter the number :";
    cin>>n;
    stack<char>st;
    balancedParenthesisUsingStack(n, "", st);
    balancedParenthesis(n, "", n, n);
    return 0;
}