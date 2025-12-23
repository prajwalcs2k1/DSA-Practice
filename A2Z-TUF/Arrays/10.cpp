// Write a C++ program to find the Missing Number

/*
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
*/

#include<bits/stdc++.h>
using namespace std;

int usingMath(vector<int> arr, int n){
    int sum = (n * (n+1)) / 2;
    for(int ele : arr) sum -= ele;
    return sum;
}

int usingBSHelper(vector<int> &arr, int low, int high){
    while(low < high){
        int mid = low + (high - low) / 2;
        if(arr[mid] > mid) high = mid;
        else low = mid + 1;
    }

    return low;
}

int usingBS(vector<int> arr, int n){
    sort(arr.begin(), arr.end());
    return usingBSHelper(arr, 0, n);  // pass `n` to handle the last number, suppose n = 4 and the array is [0,1,2,3], passing n will return 4 else it will return 3 which is wrong
}

int main(){

    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array can't be empty!!\n";
        return 0;
    }
    vector<int> arr(n);
    cout<<"Enter the array elements in the range [0-n]: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Missing element (using Math) is: "<<usingMath(arr, n)<<endl;
    cout<<"Missing element (using Binar-Search) is: "<<usingBS(arr, n)<<endl;
    return 0;
}