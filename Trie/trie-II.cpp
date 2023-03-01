//https://takeuforward.org/data-structure/implement-trie-ii/

// Problem Statement:  Implement a data structure ”TRIE” from scratch. Complete some functions.

// 1) Trie(): Initialize the object of this “TRIE” data structure.

// 2) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.

// 3) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.

// 4) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

// 5) erase(“WORD”): Delete this string “WORD” from the “TRIE”.

// Note:

// 1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

//==========================================================================================================

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    int countEndWith = 0;
    int countPrefix = 0;

    bool containsKey(char key){
        return (links[key - 'a'] != NULL);
    }

    Node* get(char key){
        return links[key - 'a'];
    }

    void put(char key, Node* node){
        links[key - 'a'] = node;
    }

    int getEnd(){
        return countEndWith;
    }

    int getPrefix(){
        return countPrefix;
    }

    void increaseEnd(){
        countEndWith++;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void reducePrefix(){
        countPrefix--;
    }

    void deleteEnd(){
        countEndWith--;
    }

};

class Trie {

    private:
        Node* root;
    
    public :
        Trie(){
            root = new Node();
        }

        void insert(string & word){
            
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){

                    node->put(word[i], new Node());
                }

                //move to next
                node = node->get(word[i]);
                node->increasePrefix();
            }

            node->increaseEnd();
        }

        int countWordsEqualTo(string &word){
            
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){

                    return 0;
                }

                //move to next
                node = node->get(word[i]);
                
            }

            return node->getEnd();
        }

        int countWordsStartingWith(string & word) {
        
            Node* node = root;

            for(int i=0; i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }

                node = node->get(word[i]);
            }

            node->getPrefix();
        
        }

        //Assumption is that word already exists else first call countWordsEqualTo 
        void erase(string & word) {
            Node* node = root;

            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return;
                }

                node= node->get(word[i]);
                node->reducePrefix();
            }

            node->deleteEnd();
        }    
 
};

int main() {
    Trie T;

    vector<string>value = {"apple", "apple", "apps", "apps", "hel"};

    T.insert(value[0]);
    T.insert(value[1]);
    T.insert(value[2]);
    T.insert(value[3]);

    //does not work  
    // T.insert("apps");
    // to have it work
//     void insert(const string& word) {
//     // ...
//      }
// When you pass a string literal like "apple" to the insert function, it creates a temporary object of type std::string. 
// The insert function, however, takes a non-const lvalue reference to a string, 
// which means that it expects an object that is both an lvalue (i.e., has a named memory location) 
// and is not const (i.e., can be modified).

// ÷\In C++, an lvalue refers to an object that occupies some identifiable location in memory (i.e., has an address),
//  while an rvalue refers to a value that is not an lvalue, i.e., it does not have an identifiable location in memory.
// int a = 10;
// int b = 20;
// int c = a + b;
//Here, a and b are lvalues because they are variables that occupy a memory location, and c is an lvalue because it is a variable 
// that is assigned a value. However, 10 and 20 are rvalues because they are values that are not stored in any memory location.

 



    string word1 = "apps";
    cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
    string word2 = "abc";
    cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
    string word3 = "ap";
    cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
    <<endl;
    string word4 = "appl";
    cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
    <<endl;
    T.erase(word1);
    cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
    return 0;
}