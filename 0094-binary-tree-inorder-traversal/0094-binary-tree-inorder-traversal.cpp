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
    // Morris traversal's (concept of threatend-binary tree)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> st;
        TreeNode *curr=root;
        while(!st.empty() || curr!=NULL)
        {
            if(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=st.top(); 
                st.pop();
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        
        return ans;
        
    }
};