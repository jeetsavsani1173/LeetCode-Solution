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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int key) {
        if(root==NULL) return new TreeNode(key);
        TreeNode* curr=root; 
        // find insert position it will be always leaf node..
        while(true){
            if(curr->val<key){
                if(curr->right) curr=curr->right;
                else{
                    curr->right=new TreeNode(key);
                    break;
                }
            }else{
                if(curr->left) curr=curr->left;
                else{
                    curr->left=new TreeNode(key);
                    break;
                }
            }
        }
        return root;
    }
};