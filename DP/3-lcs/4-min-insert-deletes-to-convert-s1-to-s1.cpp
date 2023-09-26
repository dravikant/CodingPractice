/*
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters 
from/in str1 so as to transform it into str2. It could be possible that the same character needs 
to be removed/deleted from one point of str1 and inserted to some another point.

get the lcs .. remaining chars to be deleted from s1 and remaining chars to be inserted from s2 to s1

*/

//{ Driver Code Starts
#include <vector>
#include<string>
#include<iostream>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	vector<vector<int> > table;
	
	int bottomup(int m, int n, string s1, string s2){
	    
	    
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            
	            if(s1[i-1]==s2[j-1]){
	                table[i][j] = 1 + table[i-1][j-1];
	            }
	            else{
	                table[i][j] = max(table[i-1][j],table[i][j-1]);
	            }
	        }
	    }
	    
	    return table[m][n];
	}
	
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    
	    if(m==0){
	        return n;
	    }
	    if(n==0){
	        return m;
	    }
	    
	    table.clear();
	    table.resize(m+1,vector<int>(n+1,0));
	    int lcs = bottomup(m,n,str1,str2);
	    return (m-lcs)+(n-lcs);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends