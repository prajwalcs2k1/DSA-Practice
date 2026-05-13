// Write a C++ program to print all K largest elements from the input array

#include<bits/stdc++.h>
using namespace std;

vector<int> KLargestElems(vector<int> &arr, int n, int K){
    vector<int> res(K);

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size() > K) pq.pop();
    }

    int i = K-1;
    while(!pq.empty()){
        res[i] = pq.top();
        pq.pop();
        i--;
    }

    return res;
}

int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];

    int K;
    cout<<"Enter the value of K: ";
    cin>>K;

    if((K <= 0) || (K > n)){
        cout<<"Invalid K value!\n";
        return 0;
    }

    // T.C. is O(N*log(K))
    vector<int> res = KLargestElems(arr, n, K);
    cout<<"Output: ";
    for(int ele : res) cout<<ele<<" ";

    cout<<"\n";

    return 0;
}