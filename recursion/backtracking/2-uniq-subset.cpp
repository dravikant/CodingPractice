/*
https://practice.geeksforgeeks.org/problems/subsets-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

make a set to find uniq
*/

//{ Driver Code Starts
#include <set>
#include<vector>
#include<iostream>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    set<vector<int>> s;
    
    void uniqsub(vector<int>& arr, int idx,vector<int>& cad){
        if(idx == arr.size()){
            s.insert(cad);
            return;
        }
        
        //make a choice
        
        uniqsub(arr,idx+1,cad);
        cad.push_back(arr[idx]);
        uniqsub(arr,idx+1,cad);
        cad.pop_back();
        
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        s.clear();
        vector<int>cad;
        sort(arr.begin(),arr.end());
        uniqsub(arr,0,cad);
        
        vector<vector<int> >  ans;
        
        set<vector<int>>::iterator it = s.begin();
        
        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends