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
    int find_index(vector<int> &a,int s,int e,int t)
    {
        for(int i=s;i<=e;i++)
        {
            if(a[i]==t) return i;
        }
        return e;
    }
    TreeNode* buildTree(vector<int> &in,vector<int> &pre,int n,int s1,int e1,int s2,int e2)
    {
        if(s1>e1 || s2>e2){
            return NULL;
        }
        int index=find_index(in,s1,e1,pre[s2]);
        TreeNode* curr=new TreeNode(pre[s2]);
        int mid=s2+(index-s1);
        curr->left=buildTree(in,pre,n,s1,index-1,s2+1,mid);
        curr->right=buildTree(in,pre,n,index+1,e1,mid+1,e2);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(inorder,preorder,n,0,n-1,0,n-1);
    }
};