// Find ceil of an element in a sorted array

#include<bits/stdc++.h>
using namespace std;

int ceilElement(int n, int*arr, int target){
	if(!n) return -1;
	int low = 0, high = n-1;
	int ans = -1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == target) return target;
		else if(target < arr[mid]){
			ans = arr[mid];
			high = mid - 1;
		}else{
			low = mid + 1 ;
		}

	}

	return ans;
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
	cout<<"Enter the target element: ";
	cin>>target;
	cout<<"Ceil of "<<target<<" is : "<<ceilElement(n, arr, target)<<endl;
	return 0;
}