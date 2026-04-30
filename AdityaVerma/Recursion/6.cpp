// Write a C++ program to print the subsets of a set

#include<bits/stdc++.h>
using namespace std;

void subSets(vector<int>&set, int n, vector<int>helper, int i){
    if(i == n){
        for(auto it : helper) cout<<it<<" ";
        cout<<endl;
        return;
    }

    subSets(set, n, helper, i+1);
    helper.push_back(set[i]);
    subSets(set, n, helper, i+1);
    return;
}

int main(){

    int n;
    cout<<"Enter the size of the set : ";
    cin>>n;
    vector<int>set(n);
    cout<<"Enter the elements in the set : ";
    for(int i=0; i<n; i++){
        cin>>set[i];
    }
    vector<int>helper;
    subSets(set, n, helper, 0);

    return 0;
}