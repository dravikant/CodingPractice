/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

    void inorder(TreeNode* root){

        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            inorder(root->left);
        }

        ans.push_back(root->val);

        if(root->right != NULL){
            inorder(root->right);
        }


    }

    //inorder is left->root->right
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        // inorder(root);

        stack<TreeNode *> s;

        TreeNode *current = root;
        
        while(!s.empty() || current != NULL){

            //go till leftmost
            while(current != NULL){
                s.push(current);
                current= current->left;
            }

            //current is NULL
            //we are done processing atleast left subtree so print the node and process right subtree if any
            if(!s.empty()){
                current = s.top();
                s.pop();
                ans.push_back(current->val);
                current = current->right;
            }
            
        }


        return ans;
    }
};