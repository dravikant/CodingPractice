/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*/

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bs(vector<int>& nums, int target, bool left){
        int low = 0;
        int high = nums.size() -1;
        int ans = -1;

        while(low <=high) {

            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                ans = mid;
                if (left){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(nums[mid] < target){
                low = mid +1;   
            }
            else{
                high = mid - 1;
            }

            

        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left =bs(nums,target,true);
        ans.push_back(left);
        if(left == -1){
            
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(bs(nums,target,false));
        return ans;
    }
};

int main(){

}