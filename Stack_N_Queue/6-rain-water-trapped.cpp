/*
https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10


*/

//{ Driver Code Starts
#include<vector>
#include<iostream>
using namespace std;



    long long trappingWater(int arr[], int n){
        
        long long ans=0;
        
        vector<int> max_left;
        vector<int> max_right;
        
        int max_so_far=0;
        for(int i=0;i<n;i++){
            cout<<max_so_far<<endl;
            max_left.push_back(max_so_far);
            if(max_so_far < arr[i]){
                max_so_far = arr[i];
            }
        }
        
        max_so_far =0;
        
        for(int i=n-1;i>=0;i--){
            max_right.push_back(max_so_far);
            if(max_so_far < arr[i]){
                max_so_far = arr[i];
            }
        }
        
        reverse(max_right.begin(),max_right.end());
        
        for(int i=0;i<n;i++){
            cout<<max_left[i]<<" ";
        }

        cout<<endl;


        for(int i=0;i<n;i++){
            cout<<max_right[i]<<" ";
        }

         cout<<endl;
        for(int i=0;i<n;i++){
            ans+=max(0,(min(max_right[i],max_left[i])-arr[i]));
        }
                // code here
        return ans;
    }


//{ Driver Code Starts.

int main(){
    int arr[]={7, 4, 0, 9};

    trappingWater(arr,4);
    return 0;
}
// } Driver Code Ends