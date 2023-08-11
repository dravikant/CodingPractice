/*
https://leetcode.com/problems/find-right-interval/description/
You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    //return upper bound i.e. elelement equal or least of the greater elements
    int upper_bound(vector<int> nums, int target){
        int low =0;
        int high = nums.size() -1;
        int ans =-1;
        while(low<=high){

            int mid = low +(high - low )/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid +1;
            }
            else {
                ans = mid;
                high = mid -1;
            }
        }

        return ans;
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> starts, ans;
        unordered_map<int,int> m;
        for(int i=0;i<intervals.size();i++){
            starts.push_back(intervals[i][0]);
            m[intervals[i][0]] = i;
        }

        sort(starts.begin(),starts.end());

        for(int i=0;i<intervals.size();i++){

            int ub = upper_bound(starts,intervals[i][1]);
            if(ub == -1){
                ans.push_back(-1);
            }
            else{
                ans.push_back(m[ub]);
            }


        }

        return ans;
    }
};