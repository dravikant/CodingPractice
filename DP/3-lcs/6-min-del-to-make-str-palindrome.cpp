/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.

lenght pf string - longest palindromic seq

*/

//{ Driver Code Starts
#include <vector>
#include<string>
#include<iostream>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

vector<vector<int> > table;

int lps(int m, int n, string s1, string s2){
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            if(s1[i-1]==s2[j-1]){
                table[i][j]= 1+table[i-1][j-1];
            }
            else{
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    
    return table[m][n];
    
}


int minDeletions(string str, int n) { 
    //complete the function here 
    if(n<2){
        return 0;
    }
    
    table.clear();
    table.resize(n+1,vector<int>(n+1,0));
    
    string s = str;
    reverse(s.begin(),s.end());
    int l = lps(n,n,str,s);
    
    return n-l;
} 