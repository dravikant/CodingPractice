/*
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

find lcs with itself such that

 if(s1[i-1]== s2[j-1] && (i!=j)){
	                    table[i][j] = 1+ table[i-1][j-1];
	                }


*/

//{ Driver Code Starts
#include<vector>
#include<string>
#include<iostream>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    vector<vector<int> > table;
	    
	    int lcs(int m, int n, string s1, string s2){
	        
	        for(int i=1;i<=m;i++){
	            for(int j=1;j<=n;j++){
	                
	                if(s1[i-1]== s2[j-1] && (i!=j)){
	                    table[i][j] = 1+ table[i-1][j-1];
	                }
	                else{
	                    table[i][j] = max(table[i-1][j],table[i][j-1]);
	                }
	                
	            }
	        }
	        
	        return table[m][n];
	    }
	    
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    table.clear();
		    int n = str.size();
		    table.resize(n+1,vector<int>(n+1,0));
		    return lcs(n,n,str,str);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends