// Write a C++ program to delete middle element of a stack using recursion.

#include<bits/stdc++.h>
using namespace std;

void deleteHelper(stack<int> &s, int mid){
    if(s.empty()) return ;
    if(s.size() == mid){
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    deleteHelper(s, mid);
    s.push(val);
    return;
}

void deleteMiddleEle(stack<int>& s){
    int mid = s.size() / 2;                 // lower middle for even, true middle for odd
    //  int mid = (s.size() - 1) / 2 + 1;  // higher middle for even, true middle for odd
    deleteHelper(s, mid + 1);
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
    deleteMiddleEle(s);
    cout<<"Stack after deleting middle element : "<<endl;
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}