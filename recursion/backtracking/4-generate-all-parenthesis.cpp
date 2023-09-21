/*

https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

n =1 {} 
n=2 {}{}  {{}}

for given n , we have to put n '{' and n '}' in the string

so there is a choice to select { or }

        generate(s+'(',open-1,close,val+1);
        generate(s+')',open,close-1,val-1);


now string starting with } is not valid and also at a given place there can not be more } than {

so we maintain a variable called val which sums up open and close with open adding to +1 and close adding to -1

so at a given point val should be always +ve or zero

        if(val < 0 || open <0 || close <0){
            return;
        }
        
        if(open == 0 && close ==0){
            ans.push_back(s);
            return;
        }

*/


//{ Driver Code Starts
//Initial Template for C++

#include <string>
#include<iostream>
#include<vector>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> ans;
    
    void generate(string s, int open , int close , int val){
        
        if(val < 0 || open <0 || close <0){
            return;
        }
        
        if(open == 0 && close ==0){
            ans.push_back(s);
            return;
        }
        
        //try 2 choices at a given positions
        generate(s+'(',open-1,close,val+1);
        generate(s+')',open,close-1,val-1);
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        ans.clear();
        
        if(n==0){
            return ans;
        }
        
        int open = n, close = n, val =0;
        
        string s="";
        
        generate(s,open,close,val);
        
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends