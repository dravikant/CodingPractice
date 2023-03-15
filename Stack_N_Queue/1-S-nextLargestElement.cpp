/*

https://www.geeksforgeeks.org/next-greater-element/

Given an array, print the Next Greater Element (NGE) for every element. 

The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1. 

Example: 

Input: arr[] = [ 4 , 5 , 2 , 25 ]
Output:  4      –>   5
               5      –>   25
               2      –>   25
              25     –>   -1

brute force:

    for (i = 0; i < n; i++) {
        next = -1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
    }


for every element, we have to look at its right part

so better start from right element .. we know for rightmost element ans will be -1

now push this element to stack

for all subsequent elements (n-2 to 0 index)

check if top of stack is greater .. if so that is the ans

else pop till

1. stack becomes empty
2. top of stack is greater than current element

This makes sure that stack contents are in increasing order 


*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextgreater(vector<int>&nums){

    int n = nums.size();
    vector<int> ans;
    stack<int> s;

    ans.push_back(-1);
    s.push(nums[n-1]);

    for(int i =n-1;i>=0;i++){

        if(s.top() > nums[i]){
            ans.push_back(s.top());
        }
        else{

            while(s.size()!=0 && s.top()<nums[i]){
                s.pop();
            }

            if(s.empty()){
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top());
            }
        }
        s.push(nums[i]);

    }

    //reverse the output
    reverse(ans.begin(), ans.end());

    return ans;
}