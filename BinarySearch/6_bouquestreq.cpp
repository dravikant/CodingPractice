/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

Think of the monotonous function


As D increases -> flowers blossom increases
*/

#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:

    bool possible(vector<int>& houses, vector<int>& heaters,int r){
        vector<bool> covered (houses.size(),false);
        bool ret = true;
        for(int i=0;i<heaters.size();i++){
          
          for(int j=0;j<houses.size();j++){
              if(abs(heaters[i]-houses[j])<=r){
                  covered[j] = true;
              }
          }
          
        }

        for(int i=0;i<covered.size();i++){
            if(!covered.size())
                ret = false;
        }
        return ret;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int low = 0, high = houses.size(), ans =-1;

        while(low <= high){

            int mid = low +(high -low)/2;

            if(possible(houses,heaters,mid)){
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid +1;
            }
        }
        return ans;
        
    }
};