//https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include<vector>
#include<iostream>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    vector<long long> ans;                                         
    long long neg_index = -1;
    
    // i indicates start of the window
    for(long long i=0;i<N-K+1;i++){
        
        if(neg_index < i){
            
             do {
                neg_index++;
            } while(neg_index < N && A[neg_index] >= 0);
        }
        
        if(neg_index < i +K){
            ans.push_back(A[neg_index]);
        }
        else{
             ans.push_back(0);
        }
    }
       
    return ans;                                          
 }