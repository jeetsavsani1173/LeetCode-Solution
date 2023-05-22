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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            ans.push_back(it->val);
            if(it->left) st.push(it->left);
            if(it->right) st.push(it->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};