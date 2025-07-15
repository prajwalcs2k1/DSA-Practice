// Allocate minimum no. of maximum pages problem


#include<bits/stdc++.h>
using namespace std;

/*

	void bruteForce(int n, vector<int>&arr, int k, int i, int*minOfMax, int maxPages, int totalPages){

		if(k == 1){
			maxPages = max(maxPages , totalPages);
			*minOfMax = min(*minOfMax, maxPages);
			return;
		}

		int currPages = 0;
		for( ; i<n; i++){
			currPages += arr[i];
			maxPages = max(maxPages , currPages);
			bruteForce(n, arr, k-1, i+1, minOfMax, maxPages, totalPages - currPages);
		}

		return;
	}

*/

bool isValid(int n, vector<int>&arr, int k, int mid){
    int l = 1;
    int currPages = 0;
    for(int i=0; i<n; i++){
        if((currPages + arr[i]) > mid){
            l++;
            currPages = arr[i];
        }else{
            currPages += arr[i];
        }

        if(l > k) return false;
    }
    return !(l > k);
}


int allocateMinNoOfMaxPages(int n, vector<int>&arr, int k){
    if(k > n) return -1;
    int maxPages = INT_MIN;
    int totalPages = 0;
    for(auto it : arr){
        maxPages = max(maxPages , it);
        totalPages += it;
    }
    int ans = maxPages;
    int low = maxPages, high = totalPages;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isValid(n, arr, k, mid)){
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
    cout<<"Enter the array size: ";
    cin>>n;
    if(!n){
        cout<<"Array size cannt be 0!!"<<endl;
        return 0;
    }
    vector<int>arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the number of students: ";
    cin>>k;
    cout<<allocateMinNoOfMaxPages(n, arr, k)<<endl;
    return 0;
}