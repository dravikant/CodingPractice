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

#include<vector>
#include<iostream>
#include<stack>
using namespace std;





// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long> ans;
        
        stack<long long> s;
        
        for(int i=n-1;i>=0;i--){
            
            while((!s.empty())&& (s.top()<= arr[i])){
                s.pop();
            }
            
            if(!s.empty()){
                ans.push_back(s.top());
            }
            else{
                ans.push_back(-1);
            }
            
            s.push(arr[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends