// Given an array of integers, the task is to find the next greater element in the left side of array for each element of the array in order of their appearance in the array

/*
    -   Next greater element of an element in the array is the nearest element on the left which is greater than the current element.
    -   If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the first element is always -1.
*/

#include<bits/stdc++.h>
using namespace std;

void bruteForce(int n, vector<int>&arr){
	int i,j;
	for(i=0; i<n; i++){
		for(j=i-1; j>=0; j--){
			if(arr[j] > arr[i]){
				cout<<arr[j]<<" ";
				break;
			}
		}
		if(j < 0){
			cout<<-1<<" ";
		}
	}
	cout<<endl;
	return;
}

vector<int> optimisedApp(int n, vector<int>&arr){
    stack<int>st;
    vector<int>res(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        res[i] = st.empty() == true ? -1 : st.top();
        st.push(arr[i]);
    }
    return res;
}

int main(){

    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    if(!n){
        cout<<"Array size cannot be 0!!"<<endl;
        return 0;
    }
    vector<int> arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bruteForce(n, arr);
    vector<int>res = optimisedApp(n, arr);
    for(auto it : res){
        cout<<it<<" ";
    }

    return 0;
}