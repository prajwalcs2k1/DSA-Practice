// Find count of target element in a sorted array

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
		}
		else if(tar > arr[mid]){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return res;
}

int lastOccurence(int n, int*arr, int tar){
	if(!n) return -1;
	int low = 0, high = n-1;
	int res = -1;
	while(low <= high){
		int mid = low + (high-low)/2;
		if(tar == arr[mid]){
			res = mid + 1;
			low = mid + 1;
		}else if(tar > arr[mid]){
			low = mid + 1;
		}else high = mid - 1;
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
	int firstOcc = firstOccurence(n, arr, tarEle);
	int lastOcc = lastOccurence(n, arr, tarEle);
	if((firstOcc < 0) || (lastOcc < 0)){
		cout<<"Element does not belong in the array"<<endl;
		return 0;
	}
	cout<<"Number of times "<<tarEle<<" appears in the array is: "<<(lastOcc - firstOcc + 1)<<endl;
	return 0;
}