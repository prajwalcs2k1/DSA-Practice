// Find number of rotations in a sorted array of distinct elements

#include<bits/stdc++.h>
using namespace std;

int noOfRotations(int n, int*arr){
	if(!n) return 0;
	int low = 0, high = n - 1;
	while(low <= high){
		if (arr[low] <= arr[high]) return low;
		int mid = low + (high - low) / 2;
		int next = (mid + 1) % n;
		int prev = (mid - 1 + n) % n;
		if((arr[mid] < arr[prev]) && (arr[mid] < arr[next])) return mid;
		if(arr[low] <= arr[mid]){
			low = mid + 1;
		}else high = mid;
	}
	return 0;
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
	cout<<"No of rotations = "<<(n - noOfRotations(n, arr)) % n<<endl;
	return 0;
}