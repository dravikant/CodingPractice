/*
https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1

decision here is to add space or not

e.g. A_ or A (with and without space) with condition that for last index no space can be adeed
*/

//{ Driver Code Starts
#include <string>
#include<vector>
#include<iostream>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    
    void permute(string S, string cad, int idx){
        if(idx == S.size()){
            ans.push_back(cad);
            return;
        }
        
        if(idx == S.size()-1){
           permute(S,cad+S[idx],idx+1);
           return;
        }
        
            permute(S,cad+S[idx]+" ",idx+1);
            permute(S,cad+S[idx],idx+1);
            return;
        
        
        
    }
    
    vector<string> permutation(string S){
        // Code Here
        ans.clear();
        if(S.size()==0){
            return ans;
        }
        
        
        
        string cad ="";
        permute(S,cad,0);
        return ans;
        
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends