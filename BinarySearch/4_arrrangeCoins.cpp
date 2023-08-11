/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

https://leetcode.com/problems/arranging-coins/description/
*/

class Solution {
public:

    bool possible(int coins, long long rows){

        long long sum = rows *(rows +1)/2;
        return coins >= sum;
    }

    int arrangeCoins(int n) {

        int low =0, high = n, ans=0;

        while(low<=high){

            int mid = low + (high -low)/2;

            if(possible(n,mid)){
                ans = mid;
                // T T T F F F F ...
                low = mid+1;
            }
            else {
                high = mid -1;
            }
        }

        return ans;
        
    }
};

//monotonic function

// TTTTFFFFFFF 
// FFFFFF TTTTT
// 12345566
//986532