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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty())
        {
            int LevelSize=q.size();
            int mx=INT_MIN;
            for(int i=0;i<LevelSize;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                // temp_ans.push_back(curr->val);
                mx=max(mx,curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(mx);
        }
        
        return ans;
    }
};