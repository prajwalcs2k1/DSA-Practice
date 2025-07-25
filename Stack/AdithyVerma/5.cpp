/*

    Given the daily price of a stock for n days, your task is to calculate the stock span for each day.
    The span of the stock’s price on a given day is defined as the maximum number of consecutive days (up to the current day) the price of the stock was less than or equal to its price on the current day.

    Input Format:- 
        -   An integer n — the number of days.
        -   An array prices[0...n-1] where prices[i] denotes the stock price on day i.

    Output Format:-
        -   Return an array span[0...n-1] where span[i] denotes the span of the stock on the i-th day.

*/
#include<bits/stdc++.h>
using namespace std;

void bruteForce(int n, vector<int>&arr){
    for(int i=0; i<n; i++){
        int span = 1;
        for(int j=i-1; (j>=0) && (arr[j] <= arr[i]); j--) span++;
        cout<<span<<" ";
    }
    cout<<endl;
    return;
}

void optimisedApp(int n, vector<int>&arr){
    stack<pair<int, int>>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && (st.top().first <= arr[i])) st.pop();
        if(st.empty()){
            cout<<i+1<<" ";
        }else{
            cout<<i - st.top().second<<" ";
        }
        st.push(make_pair(arr[i] , i));
    }
    cout<<endl;
    return;
}


int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    if(!n){
        cout<<"Array size cannot be 0!!"<<endl;
        return 0;
    }
    vector<int>arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>arr[i];
    bruteForce(n, arr);
    optimisedApp(n, arr);
    return 0;
}