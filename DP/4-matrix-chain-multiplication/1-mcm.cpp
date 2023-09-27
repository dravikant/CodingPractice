/*

theory:

given array or string

 i usually start from 0
 j usually at end n

 use k to break into subproblem

 i to k and k+1 to j

 format

 int solve(vector<int> arr,int i, int j ){

        //base condition
        if( i > j ){
            return 0;
        }

        for(int k=i; k<=j ; k++){ -->loop may vary

            temp_ans = solve(arr,i,k) + solve(arr,k+1,j);

            ans = func (max,min) temp_ans 
        }

        return ans;
 }


MCM

Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.

Examples:

Input: arr[] = {40, 20, 30, 10, 30}
Output: 26000
Explanation:There are 4 matrices of dimensions 40×20, 20×30, 30×10, 10×30.
Let the input 4 matrices be A, B, C and D.
The minimum number of  multiplications are obtained by 
putting parenthesis in following way (A(BC))D.
The minimum is 20*30*10 + 40*20*10 + 40*10*30

consider two matrix

i*k and k*j

multiplication possible iff
#col of 1st matrix == #rows fo later

and cost = i*k*j and dimension of output matrix is i*j


input is single array  arr[] = {40, 20, 30, 10, 30}
dimensions
A[1] : A[0] *A[1]

A[i] : A[i-1]* A[i]


int mcm(vector<int>arr,int i,int j){ // first matrix -> i should start from 1 as A[i] : A[i-1]* A[i] and j=n

    //base condition
    // i== j is single matrix so cost is zero
    if(i >= j){
        return 0
    }


    how to run k 
                       subproblems
    k=i k= j-1          i to k and k+1 to j
    k=i+1 k=j           i to k-1 and k to j



    for(int k=i;k<j;k++){
        temp_ans= mcm(arr,i,k) + mcm(arr,k+1,j) + cost of multiplying (i,k)*(k+1,j) which is i-1*k*j
        ans=min(ans,temp_ans)
    }

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
    
    vector<vector<int> > table;
    
    int mcm(int arr[], int i, int j){
        
        if(i >= j){
            return 0;
        }
        
        if(table[i][j] != -1){
            return table[i][j];
        }
        
        int ans = INT_MAX;
        
        for(int k=i;k<j;k++){
            
            int temp = mcm(arr,i,k) + mcm(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            
            if(temp < ans){
                ans = temp;
            }
        }
        
        return table[i][j]=ans;
        
        
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        if(N<2){
            return 0;
        }
        
        table.clear();
        
        table.resize(N+1,vector<int>(N+1,-1));
        
        //pass i = 1 and j = N-1
        return mcm(arr,1,N-1);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends