// Find the index of search element in a bitonic array of positive numbers

/*
	A bitonic array is an array that:
		- First increases (strictly or non-strictly) up to a certain point, and then
		- Decreases (strictly or non-strictly) for the rest of the array.
*/

#include<bits/stdc++.h>
using namespace std;

int prevElement(int*arr, int index){
	if(index < 0) return INT_MIN;
	return arr[index];
}

int nextElement(int n, int*arr, int index){
	if(index >= n) return INT_MIN;
	return arr[index];
}

bool isPeakElement(int curr, int prev, int next){
	return (curr > prev) && (curr > next);
}

int findMaxElementIndex(int n, int*arr){
	int low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		int prev = prevElement(arr, mid-1);
		int next = nextElement(n, arr, mid+1);
		if(isPeakElement(arr[mid], prev, next)) return mid;
		else if(arr[mid] > prev) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int ascBinarySearch(int low, int high, int*arr, int target){
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == target) return mid;
		else if(target < arr[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

int dscBinarySearch(int low, int high, int*arr, int target){
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == target) return mid;
		else if(target < arr[mid]) low = mid + 1;
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
	int target;
	cout<<"Enter the target element: ";
	cin>>target;
	int indexOfMaxElement = findMaxElementIndex(n, arr);
	int indexOfSearchElement = ascBinarySearch(0, indexOfMaxElement, arr, target);
	if(indexOfSearchElement != -1){
		cout<<target<<" is present in index: "<<indexOfSearchElement<<endl;
		return 0;
	}

	indexOfSearchElement = dscBinarySearch(indexOfMaxElement, n-1, arr, target);
	if(indexOfSearchElement != -1){
		cout<<target<<" is present in index: "<<indexOfSearchElement<<endl;
		return 0;
	}else{
		cout<<target<<" is not present in the array!!"<<endl;
	}
	return 0;
}