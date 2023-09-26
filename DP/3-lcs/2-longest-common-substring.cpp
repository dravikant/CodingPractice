/*

https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given two strings. The task is to find the length of the longest common substring.


Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
*/

//{ Driver Code Starts
#include<vector>
#include<string>
#include<iostream>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        vector<vector<int> > table;
    
    
    int bottomup(int n, int m, string s1, string s2){
        
        int ans=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
            
                
                if(s1[i-1] == s2[j-1]){
                    table[i][j] = 1+ table[i-1][j-1];
                    ans=max(ans,table[i][j]);
                }
                else{
                    table[i][j] = 0;
                }
            }
        }
        
        return ans;
    }
    

    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        table.clear();
        table.resize(n+1,vector<int>(m+1,0));
        return bottomup(n,m,S1,S2);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends