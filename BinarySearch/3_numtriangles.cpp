/*
https://leetcode.com/problems/valid-triangle-number
Given an integer array nums, return the number of triplets chosen from the array
 that can make triangles if we take them as side lengths of a triangle.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int n = nums.size();
        int count =0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            int k = i+2;
            for(int j=i+1;j<n-1 && nums[i]!=0;j++){
                
                while(k<n && nums[i]+nums[j] >nums[k] ){
                    k++;
                }

                count+= k-j-1;
            }
        }

        return count;
        
    }
};