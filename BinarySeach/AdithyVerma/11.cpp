// Find the index of search element in an infinte sorted array


#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n, int*arr, int target){
	if(!n) return -1;
	if(n==1){
		if(arr[0] == target) return 0;
	}
	int low = 0, high = 1;
	while(high < n){
		if(arr[high] < target){
			low = high;
			high = 2 * high;
		}else{
			break;
		}
	}
	if(high > n) return -1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == target) return mid;
		else if(target < arr[mid]){
			high = mid - 1;
		}else low = mid + 1;
	}

	return -1;
}


int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the sorted array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int target;
	cout<<"Enter the search element: ";
	cin>>target;
	cout<<"Index of "<<target<<" is: "<<binarySearch(n, arr, target)<<endl;
	return 0;
}