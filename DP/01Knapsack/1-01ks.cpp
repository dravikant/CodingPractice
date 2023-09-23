/*
https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

Given N items where each item has some weight and profit associated with it 
and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. 
The task is to put the items into the bag such that the sum of profits associated 
with them is the maximum possible. 

Input: N = 3, W = 4, profit[] = {1, 2, 3}, weight[] = {4, 5, 1}
Output: 3

choice 

for item1  
if w1 <=W .. bag has capacity
    1. include it
    2. exclude it
else
    exclude it

code:

int KS(W,<>w,<>v,index){ --> int return 

    //base condition

    //choice --> reduce the input size


}


recursive code:

int KS(W,<>w,<>v,idx){

    //base
    if(W==0 || n == 0){
        return 0;
    }

    if(w[n-1] <=W){
        return max(
            
            //include 
            v[n-1]) + KS(W-w[n-1],w,v,idx-1),

            //exclude

            KS(W,w,v,idx-1) );
    }

    else{

        //exclude

        return KS(W,w,v,idx-1) ;

    }

}


memoise

across 3 recursive calls

  v[n-1]) + KS(W-w[n-1],w,v,idx-1),
   KS(W,w,v,idx-1) );
    KS(W,w,v,idx-1) );

  what is changing?

  W and idx

  create matrix/table for only W and idx (or n)

  int t[n+1][W+1]

    initialize to -1 to indicate not compute previously

    and everytime check if already computed then return from table 

    else compute -- update table and return

either keep it global or pass as reference across calls



int KS(W,<>w,<>v,idx){

    //base
    if(W==0 || n == 0){
        return 0;
    }

    *****************************

    if(table[n][W] != -1)
        return table[n][W]


    if(w[n-1] <=W){
        ***********
         return table[n][W]= max(
            
            //include 
            v[n-1]) + KS(W-w[n-1],w,v,idx-1),

            //exclude

            KS(W,w,v,idx-1) );
    }

    else{

        //exclude
        ***********
         return table[n][W]= KS(W,w,v,idx-1) ;

    }

}



bottom up



--> across 3 recursive calls

  v[n-1]) + KS(W-w[n-1],w,v,idx-1),
   KS(W,w,v,idx-1) );
    KS(W,w,v,idx-1) );

  what is changing?

  W and idx

  create matrix/table for only W and idx (or n)

  int t[n+1][W+1]


    last valide value is n , W
    i.e. n items and W weight of KS
    i.e. we should be able to access table[n][W]

    so initialise size   int t[n+1][W+1]
-->  

initialize

    if(W==0 || n == 0){
        return 0;
    }


--> compute


lets take example


Weight array: [1, 3, 4, 5]
Value array: [1, 4, 5, 7]
Knapsack capacity: 7




  0  1  2  3  4  5  6  7
0 0  0  0  0  0  0  0  0
1 0  1  1  1  1  1  1  1
2 0  1  1  4  5  5  5  5
3 0  1  1  4  5  6  6  9
4 0  1  1  4  5  7  8  9


int table[5][8] matrix

what does t[2][3] mean?

it mean max profit with having two elements i.e. w =[1,3] v=[1,3] and W=3

so mapping between table and weight /value array is bit different

<v><w>         0  1  2  3  4  5  6  7     ---> W
             0 0  0  0  0  0  0  0  0
1   3        1 0  1  1  1  1  1  1  1
4   3        2 0  1  1  4  5  5  5  5
5   4        3 0  1  1  4  5  6  6  9
7   5        4 0  1  1  4  5  7  8  9



back to initialisation

base case --> intialise

for(int i=0;i<=n;i++){
    for(int j=0;j<=W;j++){

        if(i==0||j==0){
            table[i][j] =0;
        }
    }
}



now this

    if(w[n-1] <=W){
        ***********
         return table[n][W]= max(
            
            //include 
            v[n-1]) + KS(W-w[n-1],w,v,idx-1),

            //exclude

            KS(W,w,v,idx-1) );
    }

    else{

        //exclude
        ***********
         return table[n][W]= KS(W,w,v,idx-1) ;

    }




 for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weights[i - 1] <= j) {
                table[i][j] = max( 
                    
                            //include it
                            table[i - 1][j - weights[i - 1]] + values[i - 1],

                            //exclude it
                            table[i - 1][j],
                );
            } else {

                 //exclude it
                table[i][j] = table[i - 1][j];
            }
        }
    }




table[i][j] = max(table[i-1][j], table[i-1][j-weight[i-1]] + value[i-1])

table[i-1][j] represents the maximum value obtained by excluding the ith item.
table[i-1][j-weight[i-1]] + value[i-1] represents the maximum value obtained by including the ith item.

*/




//{ Driver Code Starts
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
// } Driver Code Ends
class Solution
{
    public:
    
    // vector<vector<int>> vec2D(rows, vector<int>(cols, value)); 
    vector<vector<int>> table;
    //Function to return max value that can be put in knapsack of capacity W.
    
    int bottomUpKS(int W, int wt[], int val[], int n){
        
        for(int i=0;i<=n;i++){
            
            for(int j=0;j<=W;j++){
                
               
                if(i==0 || j==0){
                    table[i][j]=0;
                }
                else{    
                    if(wt[i-1] <= j){
                        
                        table[i][j] = max(
                            
                           
                            val[i-1]+table[i-1][j-wt[i-1]],
                            
                            table[i-1][j]
                            
                            );
                    }
                    else{
                        table[i][j]= table[i-1][j];
                    }
                    
                    
                }
                
            }
        }
        
        return table[n][W];
        
        
    }
    
    
    int recursiveKS(int W, int wt[], int val[], int n){
        
        
        //base condition
        //n indicates number of items
        // to access nth item wt use w[n-1]
        if(n == 0 || W == 0){
            return 0;
        }
        
        
        if(table[n][W] != -1){
            return table[n][W];
        }
        
        
        if(wt[n-1] <= W){
            //take max of include and exclude
            return table[n][W] = max(val[n-1]+recursiveKS(W-wt[n-1],wt,val,n-1),
                                    recursiveKS(W,wt,val,n-1)    );
            
        }
        
        else{
            
            return table[n][W] = recursiveKS(W,wt,val,n-1);
            
        }
        
        
    } 
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       table.clear();
       
        // table.assign(n+1, vector<int>(W+1, -1)); // Initialize the table in the constructor
   
   
     table.resize(n + 1, vector<int>(W + 1, -1));

    //   return recursiveKS(W,wt,val,n);
       
       return bottomUpKS(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends


