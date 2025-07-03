// Find the position of a search element in a reverse sorted array

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int n, int*arr, int searchEle){
    if(!n) return -1;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == searchEle) return mid + 1;
        else if(arr[mid] < searchEle) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements in descending order: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int searchEle;
    cout<<"Enter the search element: ";
    cin>>searchEle;
    cout<<"Position of the search element: "<<binarySearch(n, arr, searchEle)<<endl;
    return 0;
}