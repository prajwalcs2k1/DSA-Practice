// Write a binary search algorithm to find the position of search element from the sorted array

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n, int*arr, int tarEle){
	if(!n) return -1;
	int low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == tarEle) return mid + 1;
		else if(arr[mid] < tarEle) low = mid+1;
		else high = mid - 1;
	}
	return -1;
}


int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array elements: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int tarEle;
	cout<<"Enter the search element: ";
	cin>>tarEle;

	cout<<"The element is in position: "<<binarySearch(n, arr, tarEle)<<endl;

	return 0;
}