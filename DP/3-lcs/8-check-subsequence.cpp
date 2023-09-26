/*
https://leetcode.com/problems/is-subsequence/description/

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:

    vector<vector<int>> table;

    int lcs(int m, int n, string s, string t){

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(s[i-1]==t[j-1]){
                    table[i][j] = 1+ table[i-1][j-1];
                }
                else{
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }
            }
        }

        return table[m][n];
    }

    bool isSubsequence(string s, string t) {

        int m = s.size();
        int n = t.size();

        if(m > n){
            return 0;
        }

        table.clear();

        table.resize(m+1,vector<int>(n+1,0));

        return m == lcs(m,n,s,t);

        
    }
};