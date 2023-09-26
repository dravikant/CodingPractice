/*

https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.


same as KS i.e. we have a choice

“ABCDGH” and “AEDFHR”

consider last char H and R

both do not match either take H or R

table[n][m]=max(topdown(n-1,m,s1,s2),topdown(n,m-1,s1,s2));

but when match add 1 to match count

  return table[n][m]=1+ topdown(n-1,m-1,s1,s2);


topdown timed out on submission

*/

//{ Driver Code Starts
#include<vector>
#include<string>
#include<iostream>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    vector<vector<int> > table;
    
    int topdown(int n, int m, string s1, string s2){
        
        if(m==0 || n==0){
            return 0;
        }
        
         if(table[n][m]!=-1){
            return table[n][m];   
        }
        
         //if chars match
        if(s1[n-1]==s2[m-1]){
            return table[n][m]=1+ topdown(n-1,m-1,s1,s2);
        }
        
       
        
       
        
        else{
            return table[n][m]=max(topdown(n-1,m,s1,s2),topdown(n,m-1,s1,s2));
        }
        
    }
    
    
    int bottomup(int n, int m, string s1, string s2){
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                // if(i==0||j==0){
                //     table[i][j]=0;
                // }
                
                
                if(s1[i-1] == s2[j-1]){
                    table[i][j] = 1+ table[i-1][j-1];
                }
                else{
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }
            }
        }
        


        //debugging

         for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){

                cout<<table[i][j]<<",";
            }
            cout<<endl;
         }

        //print longest common subsequence
        //start from bottom
        /*
        as
          if(s1[i-1] == s2[j-1]){
                    table[i][j] = 1+ table[i-1][j-1];
                }
                else{
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }

         see table[i][j] = max(table[i-1][j],table[i][j-1]);

         so move back till we have same value

         once we hit 

          if(s1[i-1] == s2[j-1]){
                    table[i][j] = 1+ table[i-1][j-1];
                }

                add it to ans
        
        */
        int i=n,j=m;
        string ans="";
        while(i>=1 & j>=1){

            cout<<i<<","<<j<<endl;
            while(table[i][j]== table[i-1][j]){
                i--;
            }
            cout<<i<<","<<j<<endl;
            while(table[i][j]== table[i][j-1]){
                j--;
            }
            cout<<i<<","<<j<<endl;
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;
                j--;
            }
            cout<<i<<","<<j<<endl;
            // i=0;
            
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;


        return table[n][m];
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        if(m==0 || n==0){
            return 0;
        }
        // your code here
        table.clear();
        
        table.resize(n+1,vector<int>(m+1,0));
        
        // return topdown(n,m,s1,s2);
        return bottomup(n,m,s1,s2);
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends