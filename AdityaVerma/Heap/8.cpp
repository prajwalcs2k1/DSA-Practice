// Write a C++ program to print the Top K Frequent Elements

/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> KFreqElems(vector<int> arr, int N, int K){
    vector<int> ans;

    unordered_map<int, int> mp;

    for(int ele : arr) mp[ele]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(auto it = mp.begin(); it != mp.end(); it++){
        int ele = it->first;
        int freq = it->second;

        pq.push({freq, ele});
        if(pq.size() > K) pq.pop();
    }

    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;

    int K;
    cout<<"Enter the value of K: ";
    cin>>K;


    if((K <= 0) || (K > n)){
        cout<<"Invalid K value!\n";
        return 0;
    }

    vector<int> arr(n);
    
    cout<<"Enter the input array: ";
    for(int i=0; i<n; i++) cin>>arr[i];

    // T.C. is O(N*log(K))
    vector<int> ans = KFreqElems(arr, n, K);

    cout<<"Output: ";
    for(int ele : ans) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}