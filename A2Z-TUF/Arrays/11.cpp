// Write a C++ program to print the maximum number of consecutive 1's in the array

#include<bits/stdc++.h>
using namespace std;

int maxConsecutives(int*arr, int n){
    int res = 0;
    int count = 0, ele;
    for(int i=0; i<n; i++){
        ele = arr[i];
        if(ele == 1) count++;
        else{
            res = max(res, count);
            count = 0;
        }
    }
    res = max(res, count);
    return res;
}

int main(){
    int n;
    cout<<"Enter the array size : ";
    cin>>n;
    if(!n){
        cout<<"Array can't be empty!!\n";
        return 0;
    }
    int *arr = new int[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Max. consecutive 1's length is : "<<maxConsecutives(arr, n)<<endl;
    delete[] arr;
    return 0;
}