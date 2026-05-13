// Write a C++ program to implement MaxHeap using arrays

#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> heap;

public:
    
    MaxHeap(){}

    void insert(int val){
        heap.push_back(val);
        int index = heap.size()-1;
        while(index > 0){                                           // Heapify Up
            int parentInd = (index - 1) / 2;
            if(heap[parentInd] < heap[index]){
                swap(heap[parentInd], heap[index]);
                index = parentInd;
                parentInd = (index - 1) / 2; 
            }else break;

        }
        return;
    }

    int top() {
        return (heap.size() == 0) ? INT_MIN : heap[0];
    }

    int deleteRoot(){
        if(heap.size() == 0) return INT_MIN;

        int topEle = heap[0];

        if(heap.size() == 1){
            heap.pop_back();
            return topEle;
        }

        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();

        int index = 0;

        while(true){                               // Heapify Down
            int leftChildInd = 2*index + 1;
            int rightChildInd = 2*index + 2;

            int largestEleInd = index;
            if((leftChildInd < heap.size()) && (heap[leftChildInd] > heap[largestEleInd])){
                largestEleInd = leftChildInd;
            }

            if((rightChildInd < heap.size()) && (heap[rightChildInd] > heap[largestEleInd])){
                largestEleInd = rightChildInd;
            }

            if(largestEleInd == index) break;

            swap(heap[index], heap[largestEleInd]);
            index = largestEleInd;
        }

        return topEle;
    }
};

int main(){

    MaxHeap mxHeap;
    while(true){
        int choice;
        cout<<"1. insert()  2. top()  3. delete()\n";
        cout<<"Choose from given options: ";
        cin>>choice;

        switch(choice){
            case 1: {
                    // insertion in heap
                    int val;
                    cout<<"Enter the data to insert into max heap: ";
                    cin>>val;
                    mxHeap.insert(val);
            
                    break;
            }   

            case 2: {
                    int topEle = mxHeap.top();
                    if(topEle == INT_MIN){
                        cout<<"Max heap is empty!\n";
                    }else{
                        cout<<"Top of the max heap is : "<<topEle<<endl;
                    }
                    break;   
            }

            case 3: {
                    int deletedEle = mxHeap.deleteRoot();
                    if(deletedEle == INT_MIN){
                        cout<<"Max heap is empty!!\n";
                    }else{
                        cout<<deletedEle<<" is deleted from the max heap.\n";
                    }
                    break;
            }

            default : return 0;
        }
        cout<<"\n";
    }

    return 0;
}