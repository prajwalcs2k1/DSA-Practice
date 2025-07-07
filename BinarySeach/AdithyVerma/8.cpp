// Find the search element in a nearly sorted array with distinct elements

/* Definition of Nearly Sorted Arrays :

    => Every element may be at most one position left or right from its sorted position.
    => So, if you're looking at index mid, you should check mid, mid - 1, and mid + 1.

*/
#include<bits/stdc++.h>
using namespace std;

int findElement(int n, int*arr, int searchEle){
	if(!n) return -1;
	int low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low) / 2;
		int prev = (mid - 1 + n) % n;  // These checks also helps to validate i-1 index for circular array, if circular arrays was not in picture you could have just used (mid-1)
		int next = (mid + 1) % n;  // These checks also helps to validate i+1 index for circular array, if circular arrays was not in picture you could have just used (mid+1)
		if(arr[mid] == searchEle) return mid + 1;
		else if(searchEle == arr[next]) return next + 1;
		else if(searchEle == arr[prev]) return prev + 1;
		else if(searchEle < arr[mid]) high = mid - 2;
		else low = mid + 2;
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
	int searchEle;
	cout<<"Enter the search element: ";
	cin>>searchEle;
	cout<<"The element "<<searchEle<<" is in position: "<<findElement(n, arr, searchEle)<<endl;
	return 0;
}