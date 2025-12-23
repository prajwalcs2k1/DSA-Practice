// Write a C++ program to check if the given array is sorted and rotated

/*
    Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
    There may be duplicates in the original array.

    Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.
*/

#include<bits/stdc++.h>
using namespace std;

bool isSorted(int*arr, int n){
    int drop = 0;
    for(int i=0; i<n; i++) if(arr[i] < arr[(i-1+n) % n]) drop++;

    return (drop <= 1);
}



int main(){

    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array cannot be empty!!\n";
        return 0;
    }
    int *arr = new int[n];
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++) cin>>arr[i];

    bool res = isSorted(arr, n);
    if(res) cout<<"Array is sorted.\n";
    else cout<<"Array is not sorted.\n";
    delete[] arr;
    return 0;
}