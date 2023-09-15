/*

https://leetcode.com/problems/sliding-window-maximum/description/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

*/

#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    vector<int> ans;

    if(k > nums.size()){
        return ans;
    }
    
    //we hold the (indices of )eligible candidates of window in this
    //e.g k=3 and [1,3,-1,-3,5,3,6,7]
    // 1 nums[0] can never be eligible
    //3 is and -1 is also as subsequent elements can be further smaller
    deque<int>window;

    for(int i=0;i<k;i++){

        while(window.size() && nums[window.back()] < nums[i]){
            window.pop_back();
        }

        window.push_back(i);
    }

    //front element is index of max element
    ans.push_back(window.front());

    //i indicates end of the window
    for(int i =k ;i<nums.size();i++){
        //remove old
        //index of start of window is i-k+1 i.e. we have to remove till i-k element
        while(window.size() &&  window.front() < (i-k+1)){
            window.pop_front();
        }
        //add new number
        while(window.size() && nums[window.back()] < nums[i]){
            window.pop_back();
        }

        window.push_back(i);

        ans.push_back(window.front());
    }

    return ans;

}

int main(){
    vector<int>nums ={1,3,-1,-3,5,3,6,7};
    vector<int> ans =maxSlidingWindow(nums,3);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}