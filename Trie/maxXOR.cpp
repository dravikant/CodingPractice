// https://takeuforward.org/trie/maximum-xor-queries-trie/
// You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’ of sizes N and M respectively. 
// Find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and 
// ‘xor’ represents the bitwise xor operation. Maximum XOR of Two Numbers in an Array.


//approach : we first get binary representation of the numbers in the array
// for max result of XOR we need opposite bits for 0 we need 1 and vice-versa
// so we store the binary representation in trie and at each node we try to get the opposite bit available 

#include<bits/stdc++.h>
using namespace std;


struct Node {
    // one for 0 and other for 1
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

};

class Trie {

    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

    public:

        //inserts the binary representation of the input integer
        void insert(int num ){

            Node* node = root;

            //assuming 32 bit representation
            for(int i=31;i>=0;i++){
                
                //get the value on ith position
                int bit = (num >> i) & 1;

                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }

                node = node->get(bit);
            }
            

        }

        //for the input num returns the value in array stored in trie which has max value after XOR
        int findMax(int num) {
            Node* node = root;

            int maxNum =0; //all bit 0's

            //start with 32 bit representation of input number
            for(int i=31;i>=0;i++){

                int bit = (num >> i) & 1;

                //check if node has opposite bit
                if(node->containsKey(!bit)){
                    //we found opposite bit so xor for this bit is going to be 1
                    //so add 1 at this bit position in the answer    
                    maxNum = maxNum | (1 << i);
                    node = node->get(!bit);
                }
                else{
                    //we found the same bit , that means xor will be 0
                    // so no need to update the answer
                    node = node->get(!bit);
                }
            }

            return maxNum;
        }
};

int maxXOR(int n, int m, vector < int > & arr1, vector < int > & arr2) {
  Trie trie;
  for (int i = 0; i < n; i++) {
    trie.insert(arr1[i]);
  }
  int maxi = 0;
  for (int i = 0; i < m; i++) {
    maxi = max(maxi, trie.findMax(arr2[i]));
  }
  return maxi;
}
int main() {
  vector < int > arr1 = {6, 8};
  vector < int > arr2 = {7, 8, 2};
  int n = 2, m = 3;
  cout << maxXOR(n, m, arr1, arr2) << endl;
  return 0;
}

//Another variant of this is to get the XOR with numbers in the array which are less than certain value

// use the same solution.. only execute the query before the insertion of higher values