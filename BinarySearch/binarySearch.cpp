#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int>&nums, int target){

    int low =0;
    int high = nums.size();

    while(low<=high){

        int mid = low + (high -low)/2;

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

    vector<int> nums {10,12,30,34,65,78,102};
    cout<<binarySearch(nums,76)<<endl;

}
