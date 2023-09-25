/*
https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

Given a set of integers, the task is to divide it into two sets S1 and S2 
such that the absolute difference between their sums is minimum. 
If there is a set S with n elements, then if we assume Subset1 has m elements,
Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

problem is to dividide S

into S1  and S2 such that sum(S1)-sum(S2) is minimized

there are two unknowns S1 and S2

we know that sum(S1)+sum(S2) = totalsum

S1=totalsum-S2 --> 

minimize s1-s2 -->  minmize (totalsum -s2)-s2 = minmize (totalsum - 2 * s2)

last row of the table gives which sums are possible with all set elements included

we can use that to find out s2.

table values must be filled in so we may want to call explicitely for all sum values

	    for(int i=0;i<=sum/2;i++){
	        subsetsum(arr,i,n);
	    }
	and then whichever were possible we can use to find ans

    	    int ans = INT_MAX;
	    
	    for(int col=0;col<=sum/2;col++){
	        if(table[n][col] == 1){
    	        int diff=abs(sum-(2*col));
    	        if(ans > diff){
    	            ans = diff;
    	        }
	        }
	    }    

*/

//{ Driver Code Starts
#include <vector>
#include<cmath>
#include<iostream>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
    vector<vector<int> > table;
    
    int subsetsum(int arr[],int sum,int n){
        
        if(sum ==0){
            return table[n][sum] =1;
        }
        
        
        if(n==0){
            return table[n][sum]=0;
        }
        
        
        if(table[n][sum]!= -1){
            return table[n][sum];
        }
        
        if(arr[n-1]<=sum){
            return table[n][sum] = ( subsetsum(arr,sum,n-1) || subsetsum(arr,sum-arr[n-1],n-1));
        }
        else{
            
            return table[n][sum] = subsetsum(arr,sum,n-1);
        }
    }
    
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    table.clear();
	    
	    int sum = 0;
	    
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    
	   // if(n==1){
	   //     return sum;
	   // }
	    table.resize(n+1,vector<int>(sum+1,-1));
	    
	    for(int i=0;i<=sum/2;i++){
	        subsetsum(arr,i,n);
	    }
	    
	   // subsetsum(arr,sum,n);
	    
	    int ans = INT_MAX;
	    
	    for(int col=0;col<=sum/2;col++){
	        if(table[n][col] == 1){
    	        int diff=abs(sum-(2*col));
    	        if(ans > diff){
    	            ans = diff;
    	        }
	        }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends