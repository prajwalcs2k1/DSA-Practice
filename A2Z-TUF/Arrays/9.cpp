// Write a C++ program to find the union of 2 non-decresing arrays. The elements in the union must be in ascending order.

/*
    Note:- The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(int*arr, int*brr, int n, int m){
    vector<int>res;
    int i, j;
    i=j=0;
    while((i<n) && (j<m)){
        if((i>0) && (arr[i] == arr[i-1])){
            i++;
            continue;
        }

        if((j>0) && (brr[j] == brr[j-1])){
            j++;
            continue;
        }

        if(arr[i] == brr[j]){
            res.push_back(arr[i]);
            i++;
            j++;
        }else if(arr[i] < brr[j]){
            res.push_back(arr[i]);
            i++;
        }else res.push_back(brr[j++]);
    }

    while(i<n){
        if((i>0) && (arr[i] == arr[i-1])){
            i++;
            continue;
        }
        res.push_back(arr[i++]);
    }

    while(j<m){
        if((j>0) && (brr[j] == brr[j-1])){
            j++;
            continue;
        }
        res.push_back(brr[j++]);
    }

    return res;
}

int main(){

    int n, m, tar;
    cout<<"Enter the array sizes : ";
    cin>>n, m;
    int*arr = new int[n];
    int*brr = new int[m];
    cout<<"Enter the elements for the 1st array : ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Enter the elements for the 2nd array : ";
    for(int i=0; i<m; i++) cin>>brr[i];

    vector<int> res = findUnion(arr, brr, n, m);
    cout<<"Array after union : ";
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<"\n";
    delete[] arr;
    delete[] brr;
    return 0;
}