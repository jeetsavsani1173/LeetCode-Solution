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
    int ans;
    void dfs(TreeNode* root,long long CurrSum,int targetSum,unordered_map<long,long>&mp)
    {
        if(root==NULL) return;
        
        CurrSum+=(root->val);
        ans+=(mp[CurrSum-targetSum]);
        mp[CurrSum]++;
        
        dfs(root->left,CurrSum,targetSum,mp);
        dfs(root->right,CurrSum,targetSum,mp);
        mp[CurrSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans=0;
        unordered_map<long,long> mp;
        mp[0]=1;
        dfs(root,0ll,targetSum,mp);
        return ans;
    }
};