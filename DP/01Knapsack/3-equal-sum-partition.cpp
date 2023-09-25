/*

Given an array arr[] of size N, check if it can be partitioned 
into two parts such that the sum of elements in both parts is the same.

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.


same  as subset sum

we have to check if the total sum is even (odd sum can not be partitioned to two eqal halves)
for even sum it is a subset sum problem with target = sum/2


*/

//{ Driver Code Starts
// Initial Template for C++

#include <vector>
#include<iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int> > table;
    int topdown(int arr[], int sum, int n){
        
        if(sum ==0){
            return 1;
        }
        
        if(n==0){
            return 0;
        }
        
        if(table[n][sum] != -1){
            return table[n][sum];
        }
        
        if(arr[n-1]<= sum){
            return table[n][sum]=(topdown(arr,sum-arr[n-1],n-1)||topdown(arr,sum,n-1));
        }
        else{
            return table[n][sum]=topdown(arr,sum,n-1);
        }
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum =0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2 != 0){
            return 0;
        }
          table.clear();
          table.resize(N+1,vector<int>((sum/2)+1,-1));
        return topdown(arr,  sum/2, N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends