/*
https://leetcode.com/problems/number-of-ways-to-earn-points/description/

There is a test that has n types of questions. You are given an integer target and a 0-indexed 2D integer array types where types[i] = [counti, marksi] indicates that there are counti questions of the ith type, and each one of them is worth marksi points.

Return the number of ways you can earn exactly target points in the exam. Since the answer may be too large, return it modulo 109 + 7.

Note that questions of the same type are indistinguishable.

For example, if there are 3 questions of the same type, then solving the 1st and 2nd questions is the same as solving the 1st and 3rd questions, or the 2nd and 3rd questions.
 

Example 1:

Input: target = 6, types = [[6,1],[3,2],[2,3]]
Output: 7
Explanation: You can earn 6 points in one of the seven ways:
- Solve 6 questions of the 0th type: 1 + 1 + 1 + 1 + 1 + 1 = 6
- Solve 4 questions of the 0th type and 1 question of the 1st type: 1 + 1 + 1 + 1 + 2 = 6
- Solve 2 questions of the 0th type and 2 questions of the 1st type: 1 + 1 + 2 + 2 = 6
- Solve 3 questions of the 0th type and 1 question of the 2nd type: 1 + 1 + 1 + 3 = 6
- Solve 1 question of the 0th type, 1 question of the 1st type and 1 question of the 2nd type: 1 + 2 + 3 = 6
- Solve 3 questions of the 1st type: 2 + 2 + 2 = 6
- Solve 2 questions of the 2nd type: 3 + 3 = 6

i.e. neither we have exactly 1 unit of each item nor we have unlimited quantity of each item.


*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int mod = 1000000000+7;

    vector<vector<int>> table;

    int ways(int n, int target,  vector<vector<int>>& types){

        if(target == 0){
            return 1;
        }

        if(n==0 || target < 0){
            return 0;
        }

        if(table[n][target]!= -1){
            return table[n][target];
        }

        int ans=0;

        for(int i=0;i<=types[n-1][0];i++){

                ans+= ways(n-1,target-(i*types[n-1][1]),types)%mod;
                ans %= mod;
        }
        
        return table[n][target]=ans;

    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        
        int n = types.size();

        table.clear();
        table.resize(n+1,vector<int>(target+1,-1));

        return ways(n,target,types);
    }
};