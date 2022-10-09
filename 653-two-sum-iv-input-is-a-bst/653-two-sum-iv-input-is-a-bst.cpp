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
    vector<int> path;
    void dfs(TreeNode* root)
    {
        if(root){
            dfs(root->left);
            path.push_back(root->val);
            dfs(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        
        sort(path.begin(),path.end());
        
        bool flag=false;
        int i=0,j=path.size()-1;
        while(i<j){
            if(path[i]+path[j]==k){
                flag=true;
                break;
            }else if(path[i]+path[j]<k){
                i++;
            }else{
                j--;
            }
        }
        
        return flag;
    }
};