// Write a C++ program to print the largest subarray with sum K

#include<bits/stdc++.h>
using namespace std;

pair<int, int> bruteForce(int n, vector<int>&arr, int K){
    int st=0, en=0;
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == K){
                if(mx < (j-i+1)) {
                    mx = (j-i+1);
                    en = j;
                    st = i;
                }
            }else if(sum > K) break;
        }
    }
    return {st, en};
}

pair<int, int> optimisedApp(int n, vector<int>&arr, int K){
    int mx = INT_MIN;
    int st=0, en=0, sum=0, i=0, j=0;
    while(j < n){
        sum += arr[j];
        while(sum > K){
            sum -= arr[i];
            i++;
        }
        if(sum == K){
            if(mx < (j-i+1)){
                en = j;
                st = i;
                mx = en-st+1;
            }
        }
        j++;
    }
    return {st, en};
}


int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    if(!n){
        cout<<"Array size cannot be 0!!\n";
        return 0;
    }
    vector<int>arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    int K;
    cout<<"Enter the sum :";
    cin>>K;
    pair<int, int>res;
    res = bruteForce(n, arr, K);
    for(int i=res.first; i<=res.second; i++) cout<<arr[i]<<" ";
    cout<<"\n";

    res = optimisedApp(n, arr, K);
    for(int i=res.first; i<=res.second; i++) cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}