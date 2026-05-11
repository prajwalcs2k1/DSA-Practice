// Write a C++ program to calculate maximum area rectangle in binary matrix

#include<bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int>&arr, int n){
    stack<pair<int, int>>st;
    vector<int>res(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top().first >= arr[i]) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = st.top().second;
        st.push(make_pair(arr[i] , i));
    }
    return res;
}

vector<int> NSR(vector<int>&arr, int n){
    stack<pair<int, int>>st;
    vector<int>res(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top().first >= arr[i]) st.pop();
        if(st.empty()) res[i] = n;
        else res[i] = st.top().second;
        st.push({arr[i] , i});
    }
    return res;
}



int MAH(vector<int>arr, int n){
    vector<int> nsl = NSL(arr, n);
    vector<int> nsr = NSR(arr, n);
    int res = 0;
    for(int i=0; i<n; i++){
        int lSmallInd = nsl[i];
        int rSmallInd = nsr[i];
        lSmallInd++;
        rSmallInd--;
        res = max(res, (rSmallInd - lSmallInd + 1) * arr[i]);
    }

    return res;
}

int maxArea(vector<vector<int>>&arr, int n, int m){
    int ans = 0;
    vector<int>aux(m, 0);

    for(auto it: arr){
        for(int i=0; i<m; i++){
            if(it[i]) aux[i] += it[i];
            else aux[i] = 0;
        }
        ans = max(ans, MAH(aux, m));
    }

    return ans;
}

int main(){
    int n,m;
    cout<<"Enter the rows and columns of binary matrix :";
    cin>>n>>m;
    cout<<"Enter the array elements: ";
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>arr[i][j];
    }
    cout<<"Maxium area rectangle of binary matrix is: "<<maxArea(arr, n, m)<<endl;
    return 0;
}