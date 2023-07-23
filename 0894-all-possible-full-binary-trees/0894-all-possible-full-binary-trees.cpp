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
    vector<TreeNode*> helper(int n){
        if(n==1){
            vector<TreeNode*> bAns;
            TreeNode* bNode=new TreeNode(0);
            bAns.push_back(bNode);
            return bAns;
        }
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> lAns=helper(i);
            vector<TreeNode*> rAns=helper(n-i-1);
            
            for(auto l:lAns){
                for(auto r:rAns){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};