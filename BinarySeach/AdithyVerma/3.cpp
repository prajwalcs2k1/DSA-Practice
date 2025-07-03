// Find first & last occurence of target element in a sorted array

#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int n, int*arr, int tar){
	if(!n) return -1;
	int low = 0, high = n-1;
	int res = -1;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(tar == arr[mid]){
			res = mid + 1;
			high = mid - 1;
		}else if(tar > arr[mid]){
			low = mid + 1;
		}else high = mid - 1;
	}
	return res;
}

int lastOccurence(int n, int*arr, int tar){
	if(!n) return -1;
	int low = 0, high = n-1;
	int res = -1;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(tar == arr[mid]){
			res = mid+1;
			low = mid+1;
		}else if(tar > arr[mid]){
			low = mid+1;
		}else high = mid-1;
	}
	return res;
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
	cout<<"Enter the target element: ";
	cin>>tarEle;
	cout<<"Position of first occurence of "<<tarEle<<" is: "<<firstOccurence(n, arr, tarEle)<<endl;
	cout<<"Position of last occurence of "<<tarEle<<" is: "<<lastOccurence(n, arr, tarEle)<<endl;
	return 0;
}