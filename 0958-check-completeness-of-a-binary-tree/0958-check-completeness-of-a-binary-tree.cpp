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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(!it->left) flag=true;
            if(!flag && it->left){
                q.push(it->left);
            }else if(flag && (it->left)){
                return false;
            }
            
            if(!it->right) flag=true;
            if(!flag && it->right){
                q.push(it->right);
            }else if(flag && (it->right)){
                return false;
            }
        }
        return flag;
    }
};