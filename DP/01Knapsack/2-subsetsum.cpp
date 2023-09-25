/*

https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given an array of non-negative integers, and a value sum,
determine if there is a subset of the given set with sum equal to given sum. 

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 

pretty similar to 01 KS 

with W as sum and arr as weight array
*/


//{ Driver Code Starts
//Initial template for C++

#include<vector>
#include<iostream>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    vector<vector<int> > table;
    
    bool topdown(vector<int>arr, int sum, int n){
        
        if(sum ==0){
            return true;
        }
        
        if(n==0){
            return false;
        }
        
        if(table[n][sum]!= -1){
            return table[n][sum];
        }
        
        if(arr[n-1]<= sum){
            return table[n][sum]=(topdown(arr,sum-arr[n-1],n-1)||topdown(arr,sum,n-1));
        }
        else{
            return table[n][sum]=topdown(arr,sum,n-1);
        }
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        table.clear();
        
        int n = arr.size();
        
        table.resize(n+1,vector<int>(sum+1,-1));
        
        return topdown(arr,sum,n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends