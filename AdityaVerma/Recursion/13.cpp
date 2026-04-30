// Josephus probelm

#include<bits/stdc++.h>
using namespace std;

int optimisedApp(int n, int k){
    if(n==1) return 0;
    return (optimisedApp(n-1, k) + k) % n;
}

int bruteForce(int k, vector<int> &arr){
    if(arr.size() == 1) return arr[0];
    int n = arr.size();
    int pos = 0;
    while(n != 1){
        pos = (pos + k-1) % n;
        arr.erase(arr.begin() + pos);
        n = arr.size();
    }
    return arr[0];
}


int main(){

    int n, k;
    cout<<"Enter the values of n & k :";
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }
    cout<<bruteForce(k, arr)<<endl;
    cout<<optimisedApp(n, k) + 1<<endl;
    return 0;
}