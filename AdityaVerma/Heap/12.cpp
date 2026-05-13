// Write a C++ program to find the sum of K1th & K2th smallest elements from the array

#include<bits/stdc++.h>
using namespace std;

int findSum(vector<int> arr, int N, int K1, int K2){
    int ans = 0;

    priority_queue<int> pq;

    for(int i=0; i<N; i++){
        pq.push(arr[i]);

        if(pq.size() > K2) pq.pop();
    }

    ans += pq.top();
    while(pq.size() > K1) pq.pop();

    ans += pq.top();
    return ans;
}

int main(){

    int N;
    cout<<"Enter the array size: ";
    cin>>N;

    vector<int> arr(N);
    cout<<"Enter the array elements: ";
    for(int i=0; i<N; i++) cin>>arr[i];

    int K1, K2;
    cout<<"Enter the K1 and K2 values: ";
    cin>>K1>>K2;

    if((K1 <= 0) || (K2 <= 0) || (K1 > N) || (K2 > N) || (K1 == K2)){
        cout<<"Invalid K values provided!\n";
        return 0;
    }

    int A, B;
    A = (K1 < K2) ? K1 : K2;
    B = (K1 > K2) ? K1 : K2;

    cout<<"Sum of K1 & K2 smallest is: "<<findSum(arr, N, A, B)<<endl;

    return 0;
}