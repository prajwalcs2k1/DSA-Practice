// Write a C++ program to implement Min Stack ( with extra space)

#include<bits/stdc++.h>
using namespace std;

class MinStack{
    private:
        stack<int> st, minSt;
    public : 
        MinStack() {}

        void push(int val){
            if(minSt.empty()){
                st.push(val);
                minSt.push(val);
            }else {
                if(val <= minSt.top()) minSt.push(val);
                st.push(val);
            }
            cout<<"Element pushed to stack.\n";
            return;
        }

        void pop(){
            if(st.empty()){
                cout<<"Oops!! stack is empty.\n";
            }else{
                if(minSt.top() == st.top()){
                    minSt.pop();
                }
                st.pop();
            }
            return;
        }

        void top(){
            if(st.empty()){
                cout<<"Oops!! stack is empty.\n";
            }else{
                cout<<"Top element of the stack is: "<<st.top()<<endl;
            }
            return;
        }

        void getMin(){
            if(st.empty()){
                cout<<"Oops!! stack is empty.\n";
            }else{
                cout<<"Minimum element from the stack is: "<<minSt.top()<<endl;
            }
            return;
        }
};


int main(){
    int choice;
    bool flag = false;
    MinStack st;
    while(true){
        cout<<"Select operations from below\n";
        cout<<"1. push() 2. pop() 3. top() 4. getMin()\n";
        cin>>choice;
        if((choice <= 0) || (choice >= 5)) flag = true;
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
        if(flag) break;
    }
    return 0;
}