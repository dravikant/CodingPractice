/*
Problem:
https://leetcode.com/problems/median-of-two-sorted-arrays/
https://www.youtube.com/watch?v=NTop3VTjmxk

There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both arrays ).

The overall run time complexity should be O(log (m+n)).

arr1 = [1,4,7,10,12], arr2 = [2,3,6,15] o/p  [1,2,3,4,   *6*,     7,10,12,15]


Approach:

we can simply use merge sort to get sorted array an return middle element 

but we need to care about middle element only and not other

so say array1 has len m while the other has len n, the we are only interested in element at position (m+n)/2


We will partition both the arrays in such a way that the left half of the partition will contain elements,
 which will be there when we merge them, till the median element and rest in the other right half. 
 This partitioning of both arrays will be done by binary search.


take the array with min size say m // why min so that we can use its entire length

how many min elements can be there in left partition from this array -> 0
max  -> m

low = 0 and high = m




*/

// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    //use the array with min size
    if(nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2,nums1);

    
    int m = nums1.size();
    int n = nums2.size();

    //how many min elements can be there in left partition from this array -> 0
    //max  -> m so low = m and high = m
    int low =0, high = m;

    while(low <=high) {

        //how many elements we select from array1
        int cut1 = (low + high)/2;

        // (m+n+1)/2  works for both even and odd length 
        //we try to get max elements in left half so that in case of odd length we can simply return max of left half
        // say m+n =11 then we want 6 elements in left half so cut2 will be 6 -cut1(how many elements we took from array1)
        int cut2 = (m+n+1)/2 - cut1;

        //determine the corner elements from left and right halves

        int l1 = (cut1 == 0) ? INT_MIN :nums1[cut1-1];// cut-1 0 indexing
        int l2 = (cut2 == 0) ? INT_MIN :nums2[cut2-1];
        int r1 = (cut1 == m) ? INT_MAX :nums1[cut1];
        int r2 = (cut2 == n) ? INT_MAX :nums2[cut2];

        //check if partitioning is valid

        if(l1 <= r2 && l2 <= r1) {
            //if odd length
            if((m+n)%2){
                return max(l1,l2);
            }
            else
                return (max(l1,l2) + min(r1,r2))/2.0;
        }

        else if (l1 > r2) {
            high = cut1 -1;
        }
        else{
            low = cut1 + 1;
        }



    }

    return 0.0;

}

int main() {
    vector<int> nums1{1,4,7,10,12};
    vector<int>nums2 {2,3,6,15};
    
    cout<<"The Median of two sorted arrays is"<<findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}