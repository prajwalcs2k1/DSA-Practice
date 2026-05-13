// Write a C++ program to Connect Ropes to Minimise the Cost

#include<bits/stdc++.h>
using namespace std;

int connectRopes(vector<int> ropes, int N){
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<N; i++) pq.push(ropes[i]);

    while(pq.size() > 1){
        int rope1 = pq.top();
        pq.pop();
        int rope2 = pq.top();
        pq.pop();

        cost += rope1 + rope2;
        pq.push(rope1 + rope2);
    }

    return cost;
}

int main(){

    vector<int> ropes = {1, 2, 3, 4, 5};

    cout<<"Minmum cost to connect ropes is: "<<connectRopes(ropes, ropes.size())<<endl;

    return 0;
}