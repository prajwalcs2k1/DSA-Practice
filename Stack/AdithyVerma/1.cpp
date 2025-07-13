// Given an array of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array

/*
    -   Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
    -   If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
*/


#include<bits/stdc++.h>
using namespace std;

void printNextGreatestEleBF(int n, int*arr){
	int i, j;
	for(i=0; i<n; i++){
		if(i == n-1){
			cout<<-1<<endl;
			continue;
		}
		for(j=i+1; j<n; j++){
			if(arr[j] > arr[i]){
				cout<<arr[j]<<" ";
				break;
			}
		}
		if(j == n) cout<<-1<<" ";
	}
	return;
}

vector<int> printNextGreatestEleOP(int n, int*arr){
	stack<int>st;
	vector<int>res(n);
	for(int i=n-1; i>=0; i--){
		while(!st.empty() && st.top() <= arr[i]){
			st.pop();
		}
		res[i] = st.empty() ? -1 : st.top();
		st.push(arr[i]);
	}
	return res;
}


int main()
{
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	if(!n){
		cout<<"Array size cannot be 0!!"<<endl;
		return 0;
	}
	int arr[n];
	cout<<"Enter the array elements: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	printNextGreatestEleBF(n, arr);    // BruteForce solution
    vector<int>res = printNextGreatestEleOP(n, arr);        // OPtimised solution
	for(auto it:res){
		cout<<it<<" ";
	}
	return 0;
}