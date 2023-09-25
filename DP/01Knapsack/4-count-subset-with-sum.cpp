/*

https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

Given an array arr[] of length N and an integer X, 
the task is to find the number of subsets with a sum equal to X.

Examples: 

Input: arr[] = {1, 2, 3, 3}, X = 6 
Output: 3 
All the possible subsets are {1, 2, 3}, 
{1, 2, 3} and {3, 3}

Input: arr[] = {1, 1, 1, 1}, X = 1 
Output: 4 

pretty similar subset sum



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
    
    int topdown(vector<int>arr, int sum, int n){
        
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
            // return table[n][sum]=(topdown(arr,sum-arr[n-1],n-1)||topdown(arr,sum,n-1));
            //count possible with and without this nth element
            return table[n][sum]=(topdown(arr,sum-arr[n-1],n-1)+topdown(arr,sum,n-1));
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