/*
https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.


for each index , max rectangle width needs to be calculated which boils down to finding out

nearest smallest element to left  and right

area possible for rectangle 

 = (nearest_smaller_right[i]-nearest_smaller_left[i]-1)*A[i];

*/


#include<vector>
#include<stack>
#include<iostream>
using namespace std;

int largestRectangleArea(vector<int> &A) {
    
     int ans=0;
    
    int n=A.size();
    
    if(n==0)
        return 0;
        
    if(n==1)
        return A[0];
        
        
    //first get nearest smaller to left
    
    stack<int> s;
    vector<int> nearest_smaller_left;
    for(int i=0;i<n;i++){
        
        while((!s.empty())&&(A[s.top()]>=A[i])){
            s.pop();
        }
        if(!s.empty()){
            nearest_smaller_left.push_back(s.top());
        }
        else{
            nearest_smaller_left.push_back(-1);
        }
        
        s.push(i);
    }
    
    //empty the stack
    while(!s.empty()){
        s.pop();
    }
    
    //first get nearest smaller to right
    vector<int> nearest_smaller_right;
    for(int i=n-1;i>=0;i--){
        
        while((!s.empty())&&(A[s.top()]>=A[i])){
            s.pop();
        }
        if(!s.empty()){
            nearest_smaller_right.push_back(s.top());
        }else{
            //not using -1 Why? we are using n so to get index on right which can be considered as height 0
            nearest_smaller_right.push_back(n);
        }
        
        s.push(i);
    }
    
    reverse(nearest_smaller_right.begin(),nearest_smaller_right.end());
    

     for(int i=0;i<n;i++){
        cout<<nearest_smaller_left[i]<<" ";
    }
  
    cout<<endl;
     for(int i=0;i<n;i++){
        cout<<nearest_smaller_right[i]<<" ";
    }
     cout<<endl;
    for(int i=0;i<n;i++){
        cout<<((nearest_smaller_right[i]-nearest_smaller_left[i]-1)*A[i])<<" ";
        if(ans < ((nearest_smaller_right[i]-nearest_smaller_left[i]-1)*A[i])){
            ans = (nearest_smaller_right[i]-nearest_smaller_left[i]-1)*A[i];
        }
    }

    cout<<endl;
    return ans;
}

int main(){
    vector<int> A ={90, 58, 69, 70, 82, 100, 13, 57, 47, 18};

    largestRectangleArea(A);

    return 0;
}
