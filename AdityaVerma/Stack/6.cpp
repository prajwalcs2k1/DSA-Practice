// Write a C++ program to print the maximum area histogram

#include<bits/stdc++.h>
using namespace std;

int bruteForce(int n, vector<int>&arr){
    
    int mxArea = 0;
    for(int i=0; i<n; i++){
        int j = i-1;
        while((j >= 0) && (arr[j] >= arr[i])) j--;
        int leftInd = (j < 0) ? 0 : j+1;
        j = i+1;
        while((j < n) && (arr[j] >= arr[i])) j++;
        int rightInd = (j >= n) ? n-1 : j-1;
        mxArea = max(mxArea, arr[i] * (rightInd - leftInd+1));
    }
    return mxArea;
}

vector<int> nearestSmallestLeft(int n, vector<int>&arr){
    vector<int>res(n);
    stack<pair<int,int>>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top().first >= arr[i]){
            st.pop();
        }

        res[i] = st.empty() == true ? -1 : st.top().second;
        st.push({arr[i] , i});
    }

    return res;
}

vector<int> nearestSmallestRight(int n, vector<int>&arr){
    vector<int>res(n);
    stack<pair<int, int>>st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && (st.top().first >= arr[i])){
            st.pop();
        }
        res[i] = st.empty() == true ? n : st.top().second;
        st.push({arr[i] , i});
    }
    return res;
}

int optimisedApp(int n, vector<int>&arr){
    vector<int> NSL = nearestSmallestLeft(n, arr);
    vector<int> NSR = nearestSmallestRight(n, arr);
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int upperBound = NSR[i];
        int lowerBound = NSL[i];
        upperBound--;
        lowerBound++;
        ans = max(ans , (arr[i] * (upperBound - lowerBound + 1)));
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    if(!n){
        cout<<"Array size cannt be 0!!"<<endl;
        return 0;
    }
    vector<int>arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Maximum area histogram is: "<<bruteForce(n, arr)<<endl;
    cout<<"Maximum area histogram is: "<<optimisedApp(n, arr)<<endl;
    return 0;
}