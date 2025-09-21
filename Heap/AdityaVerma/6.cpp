// Write a C++ program to sort array integers based on the frequency of the integers. [ frequency[arr[i]] > frequency[arr[i+1]] ]

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;

void frequencySort(vector<int> & arr, int n){

    priority_queue<PI> maxH;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(mp.find(arr[i]) != mp.end()){
            maxH.push({mp[arr[i]] , arr[i]});
            mp.erase(arr[i]);
        }
    }
       
    cout<<"Frequent Sort array : ";
    while(!maxH.empty()){
        auto pr = maxH.top();
        maxH.pop();
        int freq = pr.first;
        int ele = pr.second;
        while(freq--){
            cout<<ele<<" ";
        }
    }
    cout<<"\n";
    return;
}

int main(){

    int n, K;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    frequencySort(arr, n);
    return 0;
}