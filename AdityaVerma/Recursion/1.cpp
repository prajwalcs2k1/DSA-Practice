// Write a C++ program to sort an array using pure recursion

// Below logic can also be applied to sorting a stack using pure recursion

#include<bits/stdc++.h>
using namespace std;

void insertArr(vector<int>&arr, int item){
    if(arr.size() <= 0 || arr.back() <= item) {
        arr.push_back(item);
        return;
    }
    int lastItem = arr.back();
    arr.pop_back();
    insertArr(arr, item);
    arr.push_back(lastItem);
    return;
}

void sortArray(vector<int>& arr){
    if(arr.size() <= 0) return ;
    int lastItem = arr.back();
    arr.pop_back();
    sortArray(arr);
    insertArr(arr, lastItem);
    return;
}

int main(){

    int n;
    cout<<"Entre the size of array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sortArray(arr);
    cout<<"Sorted Array :";
    for(auto it : arr) cout<<it<<" ";
    cout<<endl;

    return 0;
}