/*
Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.

--> we know max possible is 

A[n-1]+B[n-1]

but which one is next ?

A[n-2]+B[n-1] or A[n-1]+B[n-2]

we try both by adding to priority queue

to make sure we dont repeat a given x,y pair use set

*/
#include<vector>
#include<iostream>
#include<queue>
#include<set>

using namespace std;
vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    
    int n = A.size();
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue< pair<int,pair<int,int> >  > pq;
    
    set<pair<int,int>> s;
    
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    
    vector<int> ans;
    
    while(C--){
        
        int sum = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        
        pq.pop();
        ans.push_back(sum);
        
        if(s.find({x-1,y}) == s.end()){
            pq.push({A[x-1]+B[y],{x-1,y}});
            s.insert({x-1,y});
        }
        
        if(s.find({x,y-1}) == s.end()){
            pq.push({A[x]+B[y-1],{x,y-1}});
            s.insert({x,y-1});
        }
        
        
    }
    
    return ans;
}
