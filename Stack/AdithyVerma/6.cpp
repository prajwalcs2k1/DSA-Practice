// Write a C++ program to print the maximum area histogram

#include<bits/stdc++.h>
using namespace std;

int bruteForce(int n, vector<int>&arr){
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        int leftInd, rightInd;
        if(i == 0){
            rightInd = 0;
            while((rightInd < n) && (arr[rightInd] >= arr[i])){
                rightInd++;
            }
            rightInd -= 1;
            ans = max(ans , (arr[i] * (rightInd - 0 + 1)));
        }else if(i == (n-1)){
            leftInd = n - 1;
            while((leftInd >= 0) && (arr[leftInd] >= arr[i])){
                leftInd--;
            }
            leftInd += 1;
            ans = max(ans , (arr[i] * (i - leftInd + 1)));
        }else{
            rightInd = i + 1;
            leftInd = i - 1;
            while((leftInd >= 0) && (arr[leftInd] >= arr[i])){
                leftInd--;
            }
            while((rightInd < n) && (arr[rightInd] >= arr[i])){
                rightInd++;
            }
            leftInd += 1;
            rightInd -= 1;
            ans = max(ans , (arr[i] * (rightInd - leftInd + 1)));
        }
    }
    return ans;
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