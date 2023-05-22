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
public: // using Rerooting Technique.... pair<height,diameter>
    pair<int,int> helper(TreeNode* root)
    {
        if(root==NULL) return {0,0};
        pair<int,int> left=helper(root->left);
        pair<int,int> right=helper(root->right);
        
        pair<int,int> rres;
        rres.first=1+max(left.first,right.first);
        rres.second=max(left.first+right.first,max(left.second,right.second));
        return rres;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans=helper(root);
        return ans.second;
    }
};