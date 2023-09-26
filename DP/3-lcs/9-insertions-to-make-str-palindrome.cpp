/*
https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

idea is to find how many extra chars in the string comapred to longest palindromic subsequence
*/


//{ Driver Code Starts
//Initial template for C++

#include<vector>
#include<string>
#include<iostream> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    vector<vector<int> > table;

    int lps(int m, int n, string s, string t){
        
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                if(s[i-1]==t[j-1]){
                    table[i][j] = 1+table[i-1][j-1];
                }
                else{
                    
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }
            }
        }
        
        return table[m][n];
        
    }

    int findMinInsertions(string S){
        // code here 
        
        int n = S.size();
        if(n<2){
            return 0;
        }
        
        string s2 = S;
        reverse(s2.begin(),s2.end());
        
        table.clear();
        table.resize(n+1,vector<int>(n+1,0));
        
        return n-lps(n,n,S,s2);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends