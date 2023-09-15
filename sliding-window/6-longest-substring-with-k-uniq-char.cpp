/*

https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 
7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.

*/

#include<vector>
#include<iostream>
#include<map>
#include<string>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        unordered_map<char,int> char_map;
        //string result="";
        int max_len = INT_MIN;
        int i =0, j =0;
        int charcount =0;

        //start with smallest window i=0j=0
        //increase the wondow till condition is satisfied
        //handle all three cases 
        //if(charcount  < k){ if(charcount  > k){ if(charcount == k){

        while(j<s.size()){
            
            char current_char = s[j];
            char_map[current_char]++;
            
            charcount = char_map.size();
            
            if(charcount  < k){
                j++;
                continue;
            }
            
            if(charcount  == k){
                
                if(max_len < (j-i+1)){
                    max_len = j-i+1;
                    
                }
                
                j++;
                
                continue;
                
                
            }
            
            if(charcount > k){
                
                while(char_map.size() >k){
                    
                     char_map[s[i]]--;
                    if(char_map[s[i]]==0){
                        
                        char_map.erase(s[i]);
                        
                    }
                    
                    i++;
                }
                
                j++;
            }
            
            
            
        }
        
        return max_len;
    // your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends