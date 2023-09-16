//{ Driver Code Starts
//Initial Template for C++

#include <stack>
#include<iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void insert(stack<int>&s, int temp){
        if(s.size()==0){
            s.push(temp);
            return;
        }
        
        int top_elem = s.top();
        s.pop();
        insert(s,temp);
        s.push(top_elem);
        return;
    }
    void Reverse(stack<int> &s){
        
        if(s.size()==1){
            return;
        }
        
        int top_elem = s.top();
        s.pop();
        Reverse(s);
        insert(s,top_elem);
        return;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends