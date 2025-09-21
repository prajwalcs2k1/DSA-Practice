// Write a C++ program to print K largest elements from the given array

#include<bits/stdc++.h>
using namespace std;

vector<int> KLargestEle(vector<int> &arr, int n, int K){
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> minH;
    for(int ele : arr){
        minH.push(ele);
        if(minH.size() > K) minH.pop();
    }
    while(!minH.empty()){
        res.push_back(minH.top());
        minH.pop();
    }
    return res;
}

int main(){

    int n, K;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of K : ";
    cin>>K;
    if((K <= 0) || (K > n)){
        cout<<"Invalid K value provided!!\n";
        return 0;
    }
    vector<int> res = KLargestEle(arr, n, K);
    cout<<K<<" largest elements from the array are : ";
    for(int ele : res){
        cout<<ele<<" ";
    }
    cout<<"\n";
    return 0;
}