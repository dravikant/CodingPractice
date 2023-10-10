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

    void preorder(TreeNode* root){

        if(root == NULL){
            return;
        }

        ans.push_back(root->val);
        if(root->left){
            preorder(root->left);
        }

        if(root->right){
            preorder(root->right);
        }
        

    }

    //preorder root->left->right
    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();

        // preorder(root);

        stack<TreeNode* > s;

        TreeNode* current = root;

        while(!s.empty() || current != NULL){

            //start printing/pushing to ans as soon as we push node to stack
            //go till leftmost node
            while(current!=NULL){
                ans.push_back(current->val);
                s.push(current);
                current= current->left;
            }

            //now current is NULL and top of stack may have right subtree
            if(!s.empty()){

                current = s.top();
                s.pop();
                current = current->right;
            }

        }




        return ans;
    }
};