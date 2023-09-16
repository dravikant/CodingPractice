#include<queue>
#include<iostream>
using namespace std;

/*
https://leetcode.com/problems/k-th-symbol-in-grammar/description/

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

observe the patter 

0

0  |  1

0   1  |  1   0

0   1   1   0  | 1   0   0   1

    
    int nsize = pow(2,n-1);

    if(k <= nsize/2){
        return kthGrammar(n-1,k);
    }
    else{
        return !  kthGrammar(n-1,k-(nsize/2));
    }

*/

int kthGrammar(int n, int k) {

    // queue<int>q1,q2,iq,oq;

    // q1.push(0);
    // oq=q1;

    // for(int i=2;i<=n;i++){

    //     if(i%2==0){
    //         //
    //             iq = q1;
    //             oq = q2;
    //     }else{
    //         iq = q2;
    //         oq = q1;
    //     }

    //     while(!iq.empty()){
    //         if(iq.front()==0){
    //             oq.push(0);
    //             oq.push(1);
    //         }else{
    //             oq.push(1);
    //             oq.push(0);
    //         }

    //         iq.pop();
    //     }
    // }

    // for(int i=1;i<k;i++){
    //     oq.pop();
    // }

    // return oq.front();

    if(n==1 & k==1){
        return 0;
    }

    
    int nsize = pow(2,n-1);

    if(k <= nsize/2){
        return kthGrammar(n-1,k);
    }
    else{
        return !  kthGrammar(n-1,k-(nsize/2));
    }
    
}

int main(){
    cout<<kthGrammar(3,3)<<endl;
    return 0;
}