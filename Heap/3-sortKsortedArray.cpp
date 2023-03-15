//Given an array of n elements, where each element is at most k away from its target position, 
// devise an algorithm that sorts in O(n log k) time.

// basically for a given index i we have to look k positions ahead to get the correct element

#include<bits/stdc++.h>
using namespace std;

void sortKSortedArray(vector<int> &nums, int k) {

    priority_queue<int,vector<int>,greater<int>> minpq;

    for(int i=0;i<=k;i++){
        minpq.push(nums[i]);
    }

    int idx =0;

    for(int i=k+1;i<nums.size();i++){
        nums[idx++] = minpq.top();

        minpq.pop();

        minpq.push(nums[i]);

    }

    while (!minpq.empty())
    {
        nums[idx++] = minpq.top();
        minpq.pop();
    }
}