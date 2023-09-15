/*
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6

for 70 o/p is 2 i.e. 70 60
we stop when we get greater element i.e we try to find greater element on left

*/

//{ Driver Code Starts
#include<vector>
#include<iostream>
#include<stack>
using namespace std;



// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector <int> ans;
       stack<int> s;
       
       for(int i=0;i<n;i++){
           
           while((!s.empty())&&(price[s.top()]<= price[i])){
               s.pop();
           }
           
           if(!s.empty()){
               ans.push_back(i-s.top());
           }
           else{
               
                ans.push_back(i+1);
           }
           
           s.push(i);
       }
       
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends