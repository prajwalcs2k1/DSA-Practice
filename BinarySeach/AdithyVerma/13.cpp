// Find the minimum difference element of target element in a sorted array


#include<bits/stdc++.h>
using namespace std;

int ceilOfTarget(int n, int*arr, int target){
	int low = 0, high = n-1;
	int ans = -1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == target) return target;
		else if(target < arr[mid]){
			ans = arr[mid];
			high = mid - 1;
		}else low = mid + 1;
	}
	return ans;
}

int floorOfTarget(int n, int*arr, int target){
	int low = 0, high = n-1;
	int ans = -1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == target) return target;
		else if(target < arr[mid]){
			high = mid - 1;
		}else{
			ans = arr[mid];
			low = mid + 1;
		}
	}
	return ans;
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
	cout<<"Enter the sorted array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int target;
	cout<<"Enter the target element: ";
	cin>>target;
	if((target < arr[0]) || (target > arr[n-1])){
		cout<<"Target element is out of range of given array."<<endl;
		return 0;
	}
	int ceil = ceilOfTarget(n, arr, target);
	int floor = floorOfTarget(n, arr, target);
	int min = (abs(ceil - target) < abs(floor - target)) ? ceil : floor;
	cout<<"Minimum difference element is "<<min<<endl;
	return 0;
}