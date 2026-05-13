// Write a C++ program to implement Min Heap

#include<bits/stdc++.h>
using namespace std;

class MinHeap{

    vector<int> heap;
    int size = 0;

public:
    MinHeap(){}

    void insert(int val){
        heap.push_back(val);
        size++;

        int index = size - 1;

        while(index > 0){                           // Heapify Up
            int parentInd = (index - 1) / 2;
            if(heap[index] < heap[parentInd]){
                swap(heap[index], heap[parentInd]);
                index = parentInd;
            }else break;
        }

        return;
    }

    int top(){
        if(size == 0) return INT_MIN;
        return heap[0];
    }

    int deleteRoot(){
        if(size == 0) return INT_MIN;
        int topEle = heap[0];

        if(size == 1){
            heap.pop_back();
            size--;
            return topEle;
        }

        swap(heap[0], heap[size-1]);
        heap.pop_back();
        size--;

        int index = 0;

        while(true){                    // Heapify Down
            int leftChildInd = 2 * index + 1;
            int rightChildInd = 2 * index + 2;
            int smallestInd = index;

            if((leftChildInd < size) && (heap[leftChildInd] < heap[smallestInd])) smallestInd = leftChildInd;

            if((rightChildInd < size) && (heap[rightChildInd] < heap[smallestInd])) smallestInd = rightChildInd;

            if(smallestInd == index) break;

            swap(heap[smallestInd], heap[index]);
            index = smallestInd;
        }

        return topEle;
    }

};

int main(){

    MinHeap mnHeap;

    while(true){
        int choice;
        cout<<"1. insert()  2. top()  3. deleteRoot()\n";
        cout<<"Choose from the given choices: ";
        cin>>choice;

        switch(choice){
            case 1:{
                    int val;
                    cout<<"Enter the value to add to min heap: ";
                    cin>>val;
                    mnHeap.insert(val);
                    break;
            }

            case 2:{
                    int topEle = mnHeap.top();
                    if(topEle == INT_MIN){
                        cout<<"Min heap is empty!\n";
                    }else{
                        cout<<"The top of the min heap is: "<<topEle<<endl;
                    }
                    break;
            }

            case 3:{
                    int deletedEle = mnHeap.deleteRoot();
                    if(deletedEle == INT_MIN){
                        cout<<"Min heap is empty!\n";
                    }else{
                        cout<<deletedEle<<" deleted successfully\n";
                    }

                    break;
            }

            default : return 0;
        }
        cout<<"\n";
    }

    return 0;
}