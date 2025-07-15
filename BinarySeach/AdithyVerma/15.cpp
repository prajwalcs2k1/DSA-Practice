// Find the maximum element in a bitonic array of positive numbers

/*
	A bitonic array is an array that:
		- First increases (strictly or non-strictly) up to a certain point, and then
		- Decreases (strictly or non-strictly) for the rest of the array.
*/

#include<bits/stdc++.h>
using namespace std;

int prevElement(int n, int*arr, int index){
	if(index < 0) return INT_MIN;
	return arr[index];
}

int nextElement(int n, int*arr, int index){
	if(index >= n) return INT_MIN;
	return arr[index];
}

bool isMaxElement(int curr, int prev, int next){
	return (curr > prev) && (curr > next);
}

int findMaxElement(int n, int*arr){
	int low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		int prev = prevElement(n, arr, mid-1);
		int next = nextElement(n, arr, mid+1);
		if(isMaxElement(arr[mid] , prev, next)) return arr[mid];
		else if(arr[mid] > prev) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}


int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	if(!n){
		cout<<"Array size cannot be 0!!"<<endl;
		return 0;
	}
	int arr[n];
	cout<<"Enter the bitonic array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	cout<<findMaxElement(n, arr)<<" is the maximum element in the given bitonic array."<<endl;
	return 0;
}