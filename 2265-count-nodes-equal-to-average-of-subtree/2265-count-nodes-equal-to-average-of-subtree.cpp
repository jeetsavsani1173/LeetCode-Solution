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
    int ans=0;
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int> left=dfs(root->left);
        pair<int,int> right=dfs(root->right);
        
        int NodeCount=left.second+right.second;
        int sum=left.first+right.first;
        // if(NodeCount==0) {
        //     cout<<root->val;
        //     ans++;
        //     return {root->val,1};
        // }
        if((sum+root->val)/(NodeCount+1)==root->val){
            // cout<<root->val;
            ans++;
        }
        return {sum+root->val,NodeCount+1};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> p=dfs(root);
        // if(p.first)
        return ans;
    }
};