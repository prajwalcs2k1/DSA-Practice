// Write a C++ program to find K closest numbers of a given number

#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

void findKClosestNumbers(vector<int> &arr, int n, int K, int m){

    priority_queue<pi> maxH;
    vector<int> absDif(n);
    for(int i=0; i<n; i++){
        absDif[i] = abs(arr[i] - m);
        maxH.push({absDif[i] , arr[i]});
        if(maxH.size() > K){
            maxH.pop();
        }
    }
    
    while(!maxH.empty()){
        auto it = maxH.top();
        maxH.pop();
        cout<<it.second<<" ";
    }
    cout<<"\n";
    return ;
}

int main(){

    int n, K, m;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of K and the integer : ";
    cin>>K>>m;
    findKClosestNumbers(arr, n, K, m);
    return 0;
}