/*
https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1

Given an array of integers A[] of length N and an integer target.
You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.

For example, if arr = {2, 1}, you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target.

Input:
N = 5
A[] = {1, 1, 1, 1, 1}
target = 3
Output:
5
Explanation:
There are 5 ways to assign symbols to 
make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3




if we observe this we are actullay dividing input into two sets 

e.g. +1 + 1 + 1 - 1 + 1 = 3

s1 : +1 + 1 + 1 +1
s2 : -1

and taking their difference 


s1 + s2 = total_sum
s1-s2   = target

==================
2s1  = total_sum +target

s1 = (total_sum +target)/2;

and then solve for count the number of subsets with given sum using s1

       int sum = 0;
        int n = A.size();
        
        for(int i=0;i<n;i++){
            sum+=A[i];
        }
        
        //s1-s2 =target
        //s1+s2=sum
        
        int s1 = (target+sum)/2;
        
        //edge case
         if (sum - target < 0 || (sum - target) % 2 == 1) {
            return 0;
        }
       
        table.resize(n+1,vector<int>(s1+1,-1));
        return topdown(A,s1,n);
*/

//{ Driver Code Starts
//Initial Template for C++

#include <vector>
#include<iostream>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    vector<vector<int> > table;
    int topdown(vector<int>&A ,int target, int n){
        
       if (n == 0) {
            if (target == 0) {
                return 1; // Found a valid expression
            } else {
                return 0; // Target is not reached
            }
        }
            
        if(table[n][target]!= -1){
            return table[n][target];   
        }
        
        
        if(A[n-1] <= target){
            return table[n][target] = topdown(A,target,n-1)+topdown(A,target-A[n-1],n-1);
        }
        else{
            
            return table[n][target] = topdown(A,target,n-1);
        }
        
        
        
    }
  
  
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        table.clear();
        
        int sum = 0;
        int n = A.size();
        
        for(int i=0;i<n;i++){
            sum+=A[i];
        }
        
        //s1-s2 =target
        //s1+s2=sum
        
        int s1 = (target+sum)/2;
        
         if (sum - target < 0 || (sum - target) % 2 == 1) {
            return 0;
        }
       
        table.resize(n+1,vector<int>(s1+1,-1));
        return topdown(A,s1,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends