// Write a C++ program to find the K closest points to origin

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> KClosest(vector<vector<int>> matrix, int K){
    vector<vector<int>> ans;

    priority_queue<pair<int, pair<int, int>>> pq;

    for(auto it : matrix){
        int x = it[0];
        int y = it[1];
        int dist = pow(x, x) + pow(y, y);

        pq.push({dist, {x, y}});
        if(pq.size() > K) pq.pop();
    }

    while(!pq.empty()){
        auto [dist, point] = pq.top();
        auto [x, y] = point;
        ans.push_back({x, y});
        pq.pop();
    }

    return ans;
}

int main(){

    vector<vector<int>> matrix = {
        {1, 3},
        {-2 ,2},
        {5, 8},
        {0, 1}
    };

    int K = 2;

    vector<vector<int>> res = KClosest(matrix, K);

    cout<<"Points closest to origin are: \n";
    cout<<"[ ";
    for(auto it : res){
        cout<<"["<<it[0]<<", "<<it[1]<<"], ";
    }
    cout<<" ]\n";

    return 0;
}