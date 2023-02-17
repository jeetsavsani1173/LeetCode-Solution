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
    vector<int> nums;
    void dfs(TreeNode* root)
    {
        if(root==NULL) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        
        int ans=INT_MAX;
        for(int i=1;i<nums.size();i++)
            ans=min(ans,nums[i]-nums[i-1]);
        return ans;
    }
};