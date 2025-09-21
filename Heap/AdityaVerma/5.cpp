// Write a C++ program to prin the top K frequent numbers

#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

void findKFrequentNos(vector<int> & arr, int n, int K){

    priority_queue<pi, vector<pi>, greater<pi>> minH;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
        minH.push({mp[arr[i]], arr[i]});
        if(minH.size() > K) minH.pop();
    }

    while(!minH.empty()){
        auto it = minH.top();
        minH.pop();
        cout<<it.second<<" ";
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
    cout<<"Enter the value of K : ";
    cin>>K;
    findKFrequentNos(arr, n, K);
    return 0;
}