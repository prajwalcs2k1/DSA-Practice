// Find the search element in a sorted rotated array with distinct elements


// Note:- There's another way to solve this problem. Find the index of minimum element and apply binary search to search the element.
#include<bits/stdc++.h>
using namespace std;

int findElement(int n, int*arr, int searchEle){
	if(!n) return -1;
	int low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == searchEle) return mid + 1;
		else if(arr[low] <= arr[mid]){
			if((searchEle >= arr[low]) && (searchEle < arr[mid])){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}else{
			if((searchEle > arr[mid]) && (searchEle <= arr[high])){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
	}
	return -1;
}

int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the rotated sorted array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int searchEle;
	cout<<"Enter the search element: ";
	cin>>searchEle;
	cout<<"The element "<<searchEle<<" is in position: "<<findElement(n, arr, searchEle)<<endl;
	return 0;
}