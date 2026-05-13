// Write a C++ program to Heapify the given array ( by deafult for Max Heap)

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int index){           // Heapify Down

    int largestInd = index;
    int leftChildInd = 2*index+1;
    int rightChildInd = 2*index+2;

    if((leftChildInd < n) && (arr[leftChildInd] > arr[largestInd])) largestInd = leftChildInd;

    if((rightChildInd < n) && (arr[rightChildInd] > arr[largestInd])) largestInd = rightChildInd;

    if(largestInd != index){
        swap(arr[largestInd], arr[index]);
        heapify(arr, n, largestInd);
    }

    return;
}

int main(){

    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    vector<int> arr(n);
    cout<<"Enter the array elements : ";
    for(int i=0; i<n; i++) cin>>arr[i];

    int nonLeafInd = (n/2)-1;

    for(int i=nonLeafInd; i>=0; i--){
        heapify(arr, n, i);
    }

    cout<<"Array after heapify: ";
    for(int ele : arr) cout<<ele<<" ";
    cout<<"\n";

    return 0;
}