// User function Template for C++
#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:

    vector<vector<int>> table;
    
    bool ispalindrome(string s, int i , int j){
        
        while(i<=j){
            if(s[i++]!= s[j--]){
                return false;
            }
        }
        
        return true;
    }
    

    int pp(string str, int i, int j){
        
        if(i>=j || ispalindrome(str,i,j)){
            return 0;
        }
        
        if(table[i][j] != -1){
            return table[i][j];
        }
        
        // if(ispalindrome(str,i,j)){
        //     return 0;
        // }
        

        
        int ans = INT_MAX;
        int left=0,right=0;
        
        for(int k=i;k<j;k++){
            
            if(table[i][k]!=-1){
                left = table[i][k];
            }
            else{
                left =pp(str,i,k);
                table[i][k]=left;
            }
            
            if(table[k+1][j]!= -1){
                right = table[k+1][j];
            }
            else{
                right= pp(str,k+1,j);
                table[k+1][j]=right;
            }
            
            int temp = left+right+1;
            
            if(temp < ans){
                ans = temp;
            }
        }
        
        return table[i][j] = ans;
        
    }

    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        
        if(n<2){
            return 0;
        }
        
        table.clear();
        table.resize(n+1,vector<int>(n+1,-1));
        
        
        return pp(str,0,n-1);
    }
};