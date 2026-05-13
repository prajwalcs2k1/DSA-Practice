// Write a C++ program to sort an array based on frequency


#include<bits/stdc++.h>
using namespace std;

vector<int> freqSort(vector<int> &arr, int n){
    vector<int> ans;

    unordered_map<int, int> mp;
    for(int ele : arr) mp[ele]++;

    priority_queue<pair<int, int>> pq;

    for(auto it = mp.begin(); it != mp.end(); it++){
        int ele = it->first;
        int freq = it->second;

        pq.push({freq, ele});
    }

    while(!pq.empty()){
        int freq = pq.top().first;
        int ele = pq.top().second;
        pq.pop();
        while(freq--) ans.push_back(ele);
    }

    return ans;
}

int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;

    vector<int> arr(n);
    
    cout<<"Enter the input array: ";
    for(int i=0; i<n; i++) cin>>arr[i];


    vector<int> ans = freqSort(arr, n);

    cout<<"Output: ";
    for(int ele : ans) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}