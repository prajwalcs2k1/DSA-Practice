// Find the peak element in an array of positive numbers

/*
    Peak Element :- An element which is greater than both of its neighbors.
*/
#include<bits/stdc++.h>
using namespace std;

int prevElement(int n, int*arr, int mid){
	if(mid < 0) return -1;
	return arr[mid];
}

int nextElement(int n, int*arr, int mid){
	if(mid >= n) return -1;
	return arr[mid];
}

int peakElement(int n, int*arr){
	int low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		int prev = prevElement(n,arr, mid-1);
		int next = nextElement(n, arr, mid+1);
		if((arr[mid] > prev) && (arr[mid] > next)) return arr[mid];
		else if(prev > arr[mid]) high = mid - 1;
		else low = mid + 1;
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
	cout<<"Enter the array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	cout<<peakElement(n, arr)<<" is a peak element."<<endl;
	return 0;
}