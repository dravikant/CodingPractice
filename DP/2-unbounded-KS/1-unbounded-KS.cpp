/*

Given a set of N items, each with a weight and a value, 
represented by the array w[] and val[] respectively. 
Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. 
Return the maximum profit.
Note: Each item can be taken any number of times.

 

Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explanation: 
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total 
  weight = 1 + 1 + 1  = 3 which is <= W.


only diff is 

  if(wt[n-1] <= W){
            //take max of include and exclude
            return table[n][W] = max(val[n-1]+recursiveKS(W-wt[n-1],wt,val,n),
                                    recursiveKS(W,wt,val,n-1)    );
            
        }


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
     vector<vector<int>> table;

 int bottomUpKS(int W, int wt[], int val[], int n){
        
        for(int i=0;i<=n;i++){
            
            for(int j=0;j<=W;j++){
                
               
                if(i==0 || j==0){
                    table[i][j]=0;
                }
                else{    
                    if(wt[i-1] <= j){
                        
                        table[i][j] = max(
                            
                           
                            val[i-1]+table[i][j-wt[i-1]],
                            
                            table[i-1][j]
                            
                            );
                    }
                    else{
                        table[i][j]= table[i-1][j];
                    }
                    
                    
                }
                
            }
        }
        
        return table[n][W];
        
        
    }    
    int recursiveKS(int W, int wt[], int val[], int n){
        
        
        //base condition
        //n indicates number of items
        // to access nth item wt use w[n-1]
        if(n == 0 || W == 0){
            return 0;
        }
        
        
        if(table[n][W] != -1){
            return table[n][W];
        }
        
        
        if(wt[n-1] <= W){
            //take max of include and exclude
            return table[n][W] = max(val[n-1]+recursiveKS(W-wt[n-1],wt,val,n),
                                    recursiveKS(W,wt,val,n-1)    );
            
        }
        
        else{
            
            return table[n][W] = recursiveKS(W,wt,val,n-1);
            
        }
        
        
    } 
    
     
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
           table.clear();
       
        // table.assign(n+1, vector<int>(W+1, -1)); // Initialize the table in the constructor
   
   
     table.resize(N + 1, vector<int>(W + 1, -1));

    //   return recursiveKS(W,wt,val,n);
       
    //    return recursiveKS(W,wt,val,N);   
        return bottomUpKS(W,wt,val,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends