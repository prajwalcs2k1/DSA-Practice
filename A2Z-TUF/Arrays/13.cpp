// Write a C++ program to find the length of the longest subarray that sums to K. If no such subarray exists then return 0.
/*
    Note:- Below used is Sliding Window approach, and it only works for array with non-negative elements

    Sliding window works only when the window sum behaves **monotonically**:
        * Expanding → sum increases
        * Shrinking → sum decreases
*/


#include<bits/stdc++.h>
using namespace std;

int subArraySum(int*arr, int n, int K){
    int res = 0;
    int st = 0, en = 0, currSum = 0;
    while(en<n){
        currSum += arr[en];
        while(currSum > K){
            currSum -= arr[st++];
        }
        if(currSum == K){
            res = max(res, (en - st + 1));
        }
        en++;
    }

    return res;
}

int main(){

    int n, K;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array can't be empty!!\n";
        return 0;
    }
    int *arr = new int[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Enter the value K: ";
    cin>>K;

    cout<<"Subarray with length "<<subArraySum(arr, n, K)<<" has sum equal to "<<K<<endl;

    delete[] arr;
    return 0;
}