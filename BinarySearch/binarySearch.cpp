#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int>&nums, int target){

    int low =0;
    int high = nums.size();

    while(low<=high){

        int mid = low + (high -low)/2;

        cout<<low<<","<<high<<","<<mid<<","<<nums[mid]<<endl;

        if(nums[mid]==target){
            return mid;
        }

        else if (nums[mid]> target){
            high = mid -1;

        }
        else{
            low = mid +1;
        }
    }

    return -1;

}


int main() {

// vector<int> nums {10, 12, 30, 34, 65, 78, 102};
    // cout<<binarySearch(nums,76)<<endl;
/*
    0,7,3,34
    4,7,5,78
    4,4,4,65
    -1
*/
    vector<int> nums{2, 5, 7, 10, 15, 20, 25};

     cout<<binarySearch(nums,12)<<endl;

 /*
    0,7,3,10
    4,7,5,20
    4,4,4,15
    -1
*/
}
/*

If the element is not found, both low and high pointers will converge to the position 
where the element should have been located in the sorted array
*/
