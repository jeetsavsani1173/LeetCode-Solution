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
    map<string,int> mp;
    vector<TreeNode*> ans;
    string dfs(TreeNode* root)
    {
        if(root==NULL) return ".";
        string subTree=to_string((root->val))+'.'+dfs(root->left)+'.'+dfs(root->right);
        mp[subTree]++;
        if(mp[subTree]==2){
            ans.push_back(root);
        }
        return subTree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return ans;
        dfs(root);
        return ans;
    }
};