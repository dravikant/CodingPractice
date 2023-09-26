/*
https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

just take LCS between str and reverse of str
*/

//{ Driver Code Starts
//Initial template for C++

#include<string>
#include<vector>
#include<iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    vector<vector<int> > table;
    
    int bottomup(int m, int n, string s1, string s2){
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                if(s1[i-1]==s2[j-1]){
                    table[i][j] = 1+ table[i-1][j-1];
                }
                else{
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }
            }
        }
        
        return table[m][n];
    }
  
    int longestPalinSubseq(string A) {
        //code here
        
        int n = A.size();
        
        if(n <2){
            return n;
        }
        
        table.clear();
        table.resize(n+1,vector<int>(n+1,0));
        
        string B="";
        for(int i=n-1;i>=0;i--){
            B+=A[i];
        }
        
        return bottomup(n,n,A,B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends