//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
    int find_index(int a[],int s,int e,int t)
    {
        for(int i=s;i<=e;i++)
        {
            if(a[i]==t) return i;
        }
    }
    Node* buildTree(int in[],int post[],int n,int s1,int e1,int s2,int e2)
    {
        if(s1>e1 || s2>e2){
            return NULL;
        }
        int index=find_index(in,s1,e1,post[e2]);
        Node* curr=new Node(post[e2]);
        int mid=s2+(index-s1);
        curr->left=buildTree(in,post,n,s1,index-1,s2,mid-1);
        curr->right=buildTree(in,post,n,index+1,e1,mid,e2-1);
        return curr;
    }
    Node *buildTree(int in[], int post[], int n) {
        return buildTree(in,post,n,0,n-1,0,n-1);
    }
