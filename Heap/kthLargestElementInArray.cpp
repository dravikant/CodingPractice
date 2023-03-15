/*

when we want kth largest : use min heap

why : if we ue max heap .. we will have to insert all element  and pop k times

with min heap "of size k"  such that those k aer the largest in the array 

then with simple one pop we will gt the ans

*/

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>&nums, int k){

    priority_queue<int, vector<int>,greater<int> > minpq;

    for(int i=0;i<nums.size();i++){

        if(minpq.size()<k){
            minpq.push(nums[i]);
        }
        else{
            if(minpq.top() <nums[i] ){
                minpq.pop();
                minpq.push(nums[i]);
            }
        }

    }
    
    return minpq.top();
}


int main()
{
 
    vector<int> nums{ 1, 4, 5, 3, 19, 3 };
    int k = 3;
 
    // Function call
    cout << "K'th largest element is "
         << findKthLargest(nums, k);
    return 0;
}

//same will work for returning k largest elements in the array