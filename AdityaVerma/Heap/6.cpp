// Write a C++ program to sort a K sorted array

#include<bits/stdc++.h>
using namespace std;

void sortArr(vector<int> &arr, int N, int K){

    priority_queue<int, vector<int>, greater<int>> pq;
    int j=0;

    /*
        ------------Time Complexity------------

                Heap size remains at most:
                K+1

                For each element:
                insertion → O(log K)
                deletion → O(log K)

                Overall: O(NlogK)
    */
    for(int i=0; i<N; i++){
        pq.push(arr[i]);
        if(pq.size() > K){
            arr[j] = pq.top();
            pq.pop();
            j++;
        }
    }

    while(!pq.empty()){
        arr[j++] = pq.top();
        pq.pop();
    }

    return;
}

int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;

    int K;
    cout<<"Enter the value of K: ";
    cin>>K;

    if((K < 0) || (K > n)){
        cout<<"Invalid K value!\n";
        return 0;
    }

    vector<int> arr(n);
    cout<<"Enter the K sorted array: ";
    for(int i=0; i<n; i++) cin>>arr[i];

    // T.C. is O(N*log(K))
    sortArr(arr, n, K);

    cout<<"Array after sorting : ";
    for(int ele : arr) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}