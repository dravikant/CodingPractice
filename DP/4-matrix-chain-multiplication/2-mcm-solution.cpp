/*


https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

Given an array p[] of length n used to denote the dimensions of a series of matrices
 such that dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices.
  Find the most efficient way to multiply these matrices together. 
  The problem is not actually to perform the multiplications, 
  but merely to decide in which order to perform the multiplications
   such that you need to perform minimum number of multiplications.
    There are many options to multiply a chain of matrices because matrix multiplication is associative 
    i.e. no matter how one parenthesize the product, the result will be the same.


Input: n = 5 
p[] = {1, 2, 3, 4, 5} 
Output: (((AB)C)D) 
Explaination: The total number of multiplications are 
(1*2*3) + (1*3*4) + (1*4*5) = 6 + 12 + 20 = 38.
*/



//{ Driver Code Starts
// Initial Template for C++

#include <vector>
#include<iostream>
#include <iomanip>
using namespace std;

class Solution{
public:

    vector<vector<int> > table;
    vector<vector<int> > brackets;
    vector<string> columns;
    
    int mcm(int p[], int i , int j){
        
        if(i>=j){
            return 0;
        }
        
        if(table[i][j] != -1){
            return table[i][j];
        }
        
        int ans = INT_MAX;
        int pos = -1;
        
        for(int k=i;k<j;k++){
            
            int temp = mcm(p,i,k)+mcm(p,k+1,j)+p[i-1]*p[k]*p[j];
            
            if(temp < ans){
                ans = temp;
                pos =k;
            }
        }
        
        brackets[i][j] = pos;
        return table[i][j] = ans;
    }

    string generatebrackets(int i, int j){
        
         if (i == j) {
            return columns[i-1];
        }
        int pos = brackets[i][j];
        
        string left = generatebrackets(i,pos);
        string right = generatebrackets(pos+1,j);
        
       return "(" + left  + right + ")";
        
    }

    string matrixChainOrder(int p[], int n){
        // code here
        
        if(n<2){
            return 0;
        }
        
        table.clear();
        table.resize(n+1,vector<int>(n+1,-1));
        
        brackets.clear();
        brackets.resize(n+1,vector<int>(n+1,-1));
        
        columns.clear();
        for(char c ='A';c<='Z';c++){
            columns.push_back(string(1,c));
        }
        
        int cost = mcm(p,1,n-1);
        
        return generatebrackets(1,n-1);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends