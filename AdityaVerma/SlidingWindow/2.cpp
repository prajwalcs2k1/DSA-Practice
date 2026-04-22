// Write a C++ program to find first negative number in every window of size K

#include<bits/stdc++.h>
using namespace std;

void bruteForce(int n, vector<int>&arr, int K){
    for(int i=0; i<=(n-K); i++){
        bool neg = false;
        for(int j=i; j<(i+K); j++){
            if(arr[j] < 0){
                neg = true;
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(!neg) cout<<0<<" ";
    }
    return ;
}

void slidingWindow(int n, vector<int>&arr, int K){
    deque<int>dq;
    if(K<=0 || K>n) return;

    int st = 0, end = 0;
    while(end < n){
        if(arr[end] < 0) dq.push_back(end);
        if((end - st + 1) == K){
            while(!dq.empty() && (dq.front() < st)) dq.pop_front();
            if(!dq.empty()) cout<<arr[dq.front()]<<" ";
            else cout<<0<<" ";
            st++;
        }
        end++;
    }
    return;
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
    cout<<"Enter the K size: ";
    cin>>K;
    bruteForce(n, arr, K);
    cout<<endl;
    slidingWindow(n, arr, K);
    return 0;
}