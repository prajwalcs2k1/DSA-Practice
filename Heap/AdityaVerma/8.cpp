// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.

#include<bits/stdc++.h>
using namespace std;

int minimumCost(vector<int> &arr, int n){
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    if(n == 2) return arr[0] + arr[1];
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> minH;
    for(int i=0; i<n; i++){
        minH.push(arr[i]);
    }
    while(!minH.empty()){
        int rope1 = minH.top();
        minH.pop();
        int rope2 = minH.top();
        minH.pop();
        ans += rope1 + rope2;
        if(minH.empty()) break;
        minH.push(rope1 + rope2);
    }
    return ans;
}

int main(){

    int n;
    cout<<"Enter the size of the array of ropes: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the rope lengths : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"The minimum cost to connect all the ropes = "<<minimumCost(arr, n)<<endl;
    return 0;
}