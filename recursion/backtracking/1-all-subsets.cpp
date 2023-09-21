/*
https://practice.geeksforgeeks.org/problems/subsets-1613027340/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

find all possible subsets

take a decision for each element .. include it or leave it 

        //two choices
        //1.skip the element
        findallsubsets(A,idx+1,subset);
        //2add the element
        subset.push_back(A[idx]);
        findallsubsets(A,idx+1,subset);
        //remove the element
        subset.pop_back();

why  subset.pop_back();?
--> check the arg of the function and recursion tree

 void findallsubsets(vector<int>& A, int idx, vector<int>& subset )

 here : vector<int>& subset: passed as reference i.e. we are using the same vector across all function calls

 if we create a new copy then pop_back not required


Call: findallsubsets([1, 2, 3], 0, [], ans)
   Subset: []
   Include 1
   Call: findallsubsets([1, 2, 3], 1, [1], ans)
      Subset: [1]
      Include 2
      Call: findallsubsets([1, 2, 3], 2, [1, 2], ans)
         Subset: [1, 2]
         Include 3
         Call: findallsubsets([1, 2, 3], 3, [1, 2, 3], ans)
            Subset: [1, 2, 3]
            Add [1, 2, 3] to ans
         Backtrack: Remove 3
         Subset: [1, 2]
         Exclude 3
         Call: findallsubsets([1, 2, 3], 3, [1, 2], ans)
            Subset: [1, 2]
            Add [1, 2] to ans
         Backtrack: Remove 2
         Subset: [1]
         Exclude 2
         Call: findallsubsets([1, 2, 3], 2, [1], ans)
            Subset: [1]
            Include 3
            Call: findallsubsets([1, 2, 3], 3, [1, 3], ans)
               Subset: [1, 3]
               Add [1, 3] to ans
            Backtrack: Remove 3
            Subset: [1]
            Exclude 3
      Backtrack: Remove 2
      Subset: [1]
      Exclude 2
      Call: findallsubsets([1, 2, 3], 1, [], ans)
         Subset: []
         Exclude 1
   Backtrack: Remove 1
   Subset: []
   Exclude 1
   Include 2
   Call: findallsubsets([1, 2, 3], 1, [2], ans)
      Subset: [2]
      Include 3
      Call: findallsubsets([1, 2, 3], 2, [2, 3], ans)
         Subset: [2, 3]
         Add [2, 3] to ans
      Backtrack: Remove 3
      Subset: [2]
      Exclude 3
   Backtrack: Remove 2
   Subset: []
   Exclude 2
   Include 3
   Call: findallsubsets([1, 2, 3], 1, [3], ans)
      Subset: [3]
      Call: findallsubsets([1, 2, 3], 2, [3, 2], ans)
         Subset: [3, 2]
         Call: findallsubsets([1, 2, 3], 3, [3, 2, 1], ans)
            Subset: [3, 2, 1]
            Add [3, 2, 1] to ans
         Backtrack: Remove 1
         Subset: [3, 2]
         Exclude 1
         Call: findallsubsets([1, 2, 3], 3, [3, 2], ans)
            Subset: [3, 2]
            Add [3, 2] to ans
         Backtrack: Remove 2
         Subset: [3]
         Exclude 2
         Call: findallsubsets([1, 2, 3], 2, [3], ans)
            Subset: [3]
            Call: findallsubsets([1, 2, 3], 3, [3, 1], ans)
               Subset: [3, 1]
               Add [3, 1] to ans
            Backtrack: Remove 1
            Subset: [3]
            Exclude 1
      Backtrack: Remove 2
      Subset: [3]
      Exclude 2
   Backtrack: Remove 3
   Subset: []
   Exclude 3

Final answer: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]

*/

#include<vector>
#include<iostream>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    vector<vector<int> > ans{};
    public:
    
    void findallsubsets(vector<int>& A, int idx, vector<int>& subset ){
        
        if(idx == A.size()){
            ans.push_back(subset);
            return;
        }
        
        //two choices
        //1.skip the element
        findallsubsets(A,idx+1,subset);
        //2add the element
        subset.push_back(A[idx]);
        findallsubsets(A,idx+1,subset);
        //remove the element
        subset.pop_back();
        
    }
    
    
    vector<vector<int> > subsets(vector<int>& A)
    {
        ans.clear();
        
        // sort(A.begin(),A.end());
        // reverse(A.begin(),A.end());
        
        vector<int> subset{};
        
        findallsubsets(A,0,subset);
         sort(ans.begin(), ans.end());
        return ans;
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends