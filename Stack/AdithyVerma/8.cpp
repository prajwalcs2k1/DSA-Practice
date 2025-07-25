// Write a CPP program to calculate the total amount of rain water trapped between the blocks

/*
    Given an array where each element represents the height of a bar, how much water can be trapped after raining?
*/


#include<bits/stdc++.h>
using namespace std;

int bruteForce(int n, vector<int>&arr){
    if(!n) return 0;
    int low = 0, high = n-1;
    while((low<n) && (arr[low] == 0)) low++;
    while((high >= 0) && (arr[high] == 0)) high--;
    int totalRainWater = 0;
    while(low <= high){
        int maxLeft = arr[low];
        int maxRight = arr[low];
        for(int i=0; i<low; i++){
            maxLeft = max(maxLeft , arr[i]);
        }
        for(int i=low+1; i<=high; i++){
            maxRight = max(maxRight , arr[i]);
        }

        totalRainWater += max(0,min(maxLeft , maxRight) - arr[low]);
        low++;
    }
    return totalRainWater;
}

vector<int> rightGreatest(int n, vector<int>&arr){
    vector<int>res(n);
    int maxTower = arr[n-1];
    for(int i=n-1; i>=0; i--){
        res[i] = max(maxTower, arr[i]);
        maxTower = max(maxTower , arr[i]);
    }
    return res;
}

vector<int> leftGreatest(int n, vector<int>&arr){
    vector<int>res(n);
    int maxTower = arr[0];
    for(int i=0; i<n; i++){
        res[i] = max(maxTower, arr[i]);
        maxTower = max(maxTower , arr[i]);
    }
    return res;
}

int optimisedApp(int n, vector<int>&arr){
    vector<int>GR = rightGreatest(n, arr);
    vector<int>GL = leftGreatest(n, arr);
    int totalRainWater = 0;
    for(int i=0; i<n; i++){
        totalRainWater = totalRainWater + max(0, min(GR[i] , GL[i]) - arr[i]);
    }
    return totalRainWater;
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
    cout<<"Total trapped rain water: "<<bruteForce(n, arr)<<endl;
    cout<<"Total trapped rain water: "<<optimisedApp(n, arr)<<endl;
    return 0;
}