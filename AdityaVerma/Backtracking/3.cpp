// Write a C++ program to find the largest number in K swaps. Input is 's' where s is a string of digits

#include<bits/stdc++.h>
using namespace std;

long long findLargest(string s, int swaps, int index){
    if(!swaps || (index == s.length())){
        return stoll(s);
    }
    
    long long ans = stoll(s);
    int maxDigit = s[index] - '0';
    for(int i=index+1; i<s.length(); i++){
        maxDigit = max(maxDigit, s[i] - '0');
    }

    if(maxDigit == (s[index] - '0')) ans = max(ans, findLargest(s, swaps, index + 1));
    else{
        for(int i=index+1; i<s.length(); i++){
            if((s[i] - '0') == maxDigit){
                swap(s[index], s[i]);
                ans = max(ans, findLargest(s, swaps - 1, index + 1));
                swap(s[index], s[i]);
            }
        }
    }

    return ans;
}

int main(){

    string s;
    cout<<"Enter the string : ";
    cin>>s;
    int K;
    cout<<"Enter the value of K : ";
    cin>>K;

    cout<<"Largest no. with atmost K swaps is : "<<findLargest(s, K, 0)<<endl;
    return 0;
}