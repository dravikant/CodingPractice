//https://www.codingninjas.com/codestudio/problems/implement-trie_631356
//https://takeuforward.org/data-structure/implement-trie-1/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    //check if a char is present
    bool containsKey(char key) {
        return (links[key - 'a'] != NULL);
    }

    //insert a new key
    void put(char key, Node* node ){
        links[key - 'a'] = node;
    }

    //get the node for a given key
    Node* get(char key){
        return links[key - 'a' ];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
    
};

class Trie {

    private :

        Node* root;


    public :

        Trie() {
            root = new Node();
        }

        void insert(string word) {
            // take a dummy node pointing to root
            Node* node = root;
            //iterate over input string
            for(int i=0;i<word.size();i++){
                //check if its already present
                if(!node->containsKey(word[i])){
                    //if it is not , create one
                    node->put(word[i], new Node());
                    
                }
                //moves to next node
                node = node->get(word[i]);
            }

            //now all insertion is done
            node->setEnd();
        }

        bool search(string word) {

            //take a dummy node
            Node* node = root;

            //iterate over word
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                
                //move to next node
                node = node-> get(word[i]);
            }

            
            return node->isEnd();

        }

        
        bool startsWith(string word) {

            //take a dummy node
            Node* node = root;

            //iterate over word
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                
                //move to next node
                node = node-> get(word[i]);
            }

            
            return true;

        }



};


int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}