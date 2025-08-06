// Write a C++ program to reverse a stack using pure recursion & in contant space

#include<bits/stdc++.h>
using namespace std;

void stackReverseHelper(stack<int>&s, int item){
    if(s.empty()) {
        s.push(item);
        return;
    }
    int val = s.top();
    s.pop();
    stackReverseHelper(s, item);
    s.push(val);
    return;
}

void reverseStack(stack<int> &s){
    if(s.empty()) return;
    int val = s.top();
    s.pop();
    reverseStack(s);
    stackReverseHelper(s, val);
    return;
}

void printStackElements(stack<int> s){
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
    return;
}

int main(){

    int n;
    cout<<"Enter the size of the stack : ";
    cin>>n;
    stack<int>s;
    cout<<"Enter the stack elements : ";
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        s.push(val);
    }
    cout<<"Stack before reversing : "<<endl;
    printStackElements(s);  
    reverseStack(s);  
    cout<<"Stack after reversing : "<<endl;
    printStackElements(s);  
    return 0;
}