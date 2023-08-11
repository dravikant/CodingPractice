/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/?source=submission-ac
*/
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:

    bool possible(vector<int>& nums, int div , int threshold){
        int sum =0;
        for(int i=0;i<nums.size();i++ ){
            sum+=ceil(nums[i]*1.0/div);
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low =1, high = threshold, ans=0;
        for(int i=0;i<nums.size();i++ ){
            if (high < nums[i])
                high = nums[i];
        }

        while(low <= high){
            int mid = low + (high - low)/2;

            if(possible(nums,mid,threshold)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }

        }

        return ans;
    }
};