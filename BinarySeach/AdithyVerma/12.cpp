// Find the index of first 1 in an infinte sorted binary array


#include<bits/stdc++.h>
using namespace std;

int first1(int n, int*arr){
	if(!n) return -1;
	int ans = -1;
	int low = 0, high = 1;
	while((high < n) && (low <= high)){
		if(arr[high] != 1){
			low = high;
			high = 2 * high;
		}else{
			break;
		}
	}
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(arr[mid] == 1){
			ans = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return ans;
}

int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the binary array: ";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<"Index of first 1 is: "<<first1(n, arr)<<endl;
	return 0;
}