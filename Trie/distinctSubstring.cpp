//  Given a string of alphabetic characters. 
//Return the count of distinct substrings of the string(including the empty string) using the Trie data structure.
//https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    bool containsKey(char key){

        return (links[key - 'a']!= NULL);
    }

    void put(char key, Node* node){
        links[key - 'a']=node;
    }

    Node* get(char key){
        return links[key-'a'];
    }
};

int countDistinctSubstrings(string &w){

    //create root node
    Node *root = new Node();

    int count =0;
    int n = w.size();

    for(int i=0;i<w.size();i++){

        Node* node = root;

        for(int j=i;j<w.size();j++){
            if(!node->containsKey(w[j])){
                count++;
                node->put(w[j],new Node());
                // cout<<"alloted node for "<<w[j]<<endl;
            }
            //debugging
            // else{
            //     cout<<"skipped node for "<<w[j]<<endl;
            // }
            node= node->get(w[j]);
        }
    }

    return count+1;
}

int main() {
  string s1 = "ababa";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s1);
  cout << "\n";

  string s2 = "ccfdf";
  cout << "Total number of distinct substrings : " << countDistinctSubstrings(s2);

  return 0;
}