/*

same as median on two sorted arrays


only difference

consider 

A:  7 12 14 15      m = 4
B:  1 2 3 4 9 11    n = 6
K : 7

here how many minimum elements you should pick from A ? 0 no why?
--> len(B) is itself 6 so we have to atleast take 1 element from A so low = max(0,k-n)

now say K is given as 3

how many max element we can pick from A? is it m ? NO 
becaise m > K so high = min(m,k)


*/


#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int>&A, vector<int>&B, int K){

   if (A.size() > B.size()){
    return kthElement(B,A,K);
   }

   int m = A.size();
   int n = B.size();

   int low = max(0,k-n);
   int high = min(m,k);

while(low<=high){

    int cut1 = low + (high-low)/2;
    int cut2 = k - cut1;

    int l1 = (cut1 == 0) ? INT_MIN: A[cut1-1];
    int l2 = (cut2 == 0) ? INT_MIN: B[cut2-1];
    int r1 = (cut1 == m) ? INT_MAX: A[cut1];
    int r2 = (cut2 == n) ? INT_MAX: B[cut2];

    if(l1<= r2 && l2 <=r1){
        return max(l1,l2);
    }
    else if(l1 > r2){
        high = cut1 -1;
    }
    else{
        low = cut1 +1;
    }


   }

   return 1;

}
