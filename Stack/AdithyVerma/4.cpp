// Given an array of integers, the task is to find the nearest smaller element in the right side of array for each element of the array

/*
    -   Next smaller element of an element in the array is the nearest element on the right which is smaller than the current element.
    -   If there does not exist next smallest of current element, then next smaller element for current element is -1. For example, next smaller of the last element is always -1.
*/

#include<bits/stdc++.h>
using namespace std;

void bruteForce(int n, vector<int>&arr){
    int i, j;
    for(i=0; i<n; i++){
        if(i == n-1){
            cout<<-1<<endl;
            continue;
        }
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j >= n){
            cout<<-1<<" ";
        }
    }
    return;
}

vector<int> optimisedApp(int n, vector<int>&arr){
    vector<int>res(n);
    stack<int>st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }

        res[i] = st.empty() == true ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}


int main(){

    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    if(!n){
        cout<<"Array size cannot be 0!!"<<endl;
        return 0;
    }
    vector<int>arr(n);
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
     
    bruteForce(n, arr);
    vector<int>res = optimisedApp(n, arr);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}