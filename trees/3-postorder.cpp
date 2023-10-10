/**
 * Definition for a binary tree node.*/
#include<vector>
#include<stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int> ans;

    void postorder(TreeNode* current){

        if(current == NULL){
            return;
        }

        if(current->left){
            postorder(current->left);
        }


        if(current->right){
            postorder(current->right);
        }

        ans.push_back(current->val);
    }

    //postorder left -> right  -> root

    vector<int> postorderTraversal(TreeNode* root) {
        ans.clear();
        // postorder(root);
        
        stack<TreeNode* > s;

        TreeNode* current = root;
        
        while(!s.empty() || current!=NULL){

            //go to the leftmost node
            while(current != NULL){
                s.push(current);
                current = current->left;
            }

            //current is NULL at this point
            if(!s.empty()){

                //check the right subtree for node on top of stack
                TreeNode* temp  = s.top()->right;

                //if it is null that means we are done with left and right subtree
                if(temp == NULL){

                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    
                    //continue poping till current node represents right subtree
                    while(!s.empty() && temp == s.top()->right){
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }

                }
                else{

                    //right subtree is not null so lets process this in the same order left -> right -> root
                    //go to the top
                    current = temp;
                }



        }
        

          
        }
        
        
        return ans;
    }
};