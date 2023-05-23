/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void kLevelDown(TreeNode* root,TreeNode* blocker,int k,vector<int> &ans){
        if(root==NULL || k<0 || root==blocker) return;
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        kLevelDown(root->left,blocker,k-1,ans);
        kLevelDown(root->right,blocker,k-1,ans);
    }
    int find_path(TreeNode* root, TreeNode* target, int k,vector<int> &ans){
        if(root==NULL) return 0;
        if(root==target){
            kLevelDown(root,NULL,k,ans);
            return 1;
        }
        
        int left=find_path(root->left,target,k,ans);
        if(left>0){
            kLevelDown(root,root->left,k-left,ans);
            return 1+left;
        }
        
        int right=find_path(root->right,target,k,ans);
        if(right>0){
            kLevelDown(root,root->right,k-right,ans);
            return 1+right;
        }
        return 0;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        find_path(root,target,k,ans);
        return ans;
    }
};