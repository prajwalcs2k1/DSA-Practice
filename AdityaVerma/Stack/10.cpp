// Write a C++ program to implement Min Stack ( without extra space)

#include<bits/stdc++.h>
using namespace std;

class MinStack{
    private : 
        stack<int> minStack;
        int mnEle = -1;
    public : 
        MinStack() {}

        void push(int val){
            if(minStack.empty()){
                minStack.push(val);
                mnEle = val;
            }else if(val >= mnEle){
                minStack.push(val);
            }else{
                int eleToPush = 2 * val - mnEle;
                minStack.push(eleToPush);
                mnEle = val;
            }
            cout<<"Element pushed to stack.\n";
            return;
        }

        void pop(){
            if(minStack.empty()){
                cout<<"Stack is empty!!"<<endl;
                return;
            }

            if(mnEle <= minStack.top()){
                minStack.pop();
                if(minStack.empty()) mnEle = -1;
            }
            else{
                mnEle = 2 * mnEle - minStack.top();
                minStack.pop();
            }

            return;
        }

        void top(){
            if(minStack.empty()){
                cout<<"Stack is empty!!"<<endl;
                return;
            }

            cout<<"Top of stack is : "<<((minStack.top() >= mnEle) ? minStack.top() : mnEle)<<endl;
            return;
        }

        void getMin(){
            if(mnEle == -1){
                cout<<"Stack is empty!!"<<endl;
            }else{
                cout<<"Min Element is : "<<mnEle<<endl;
            }

            return;
        } 
};

int main(){

    MinStack st;
    int choice;
    bool flag = true;
    while(flag){
        cout<<"Select operations from below\n";
        cout<<"1. push() 2. pop() 3. top() 4. getMin()\n";
        cin>>choice;
        if((choice <= 0) || (choice >= 5)) flag = false;
        switch(choice){
            case 1:
                int input;
                cout<<"Enter the input for push operation: "<<endl;
                cin>>input;
                st.push(input);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                st.top();
                break;

            case 4:
                st.getMin();
                break;

            default : break;
        }
    }

    return 0;
}