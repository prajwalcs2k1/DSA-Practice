// Write a C++ program to print the K Closest numbers of an element X from the input array

#include<bits/stdc++.h>
using namespace std;

vector<int> KClosest(vector<int> &arr, int N, int K, int X){
    vector<int> ans;

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<N; i++){
        pq.push({abs(arr[i] - X) , arr[i]});

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

    int K, X;
    cout<<"Enter the value of K: ";
    cin>>K;

    cout<<"Enter the value of X: ";
    cin>>X;

    if((K <= 0) || (K > n)){
        cout<<"Invalid K value!\n";
        return 0;
    }

    vector<int> arr(n);
    
    cout<<"Enter the input array: ";
    for(int i=0; i<n; i++) cin>>arr[i];

    // T.C. is O(N*log(K))
    vector<int> ans = KClosest(arr, n, K, X);

    for(int ele : ans) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}