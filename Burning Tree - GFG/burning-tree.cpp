//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* targetNode;
    void dfs(Node* root,map<Node*,Node*> &mp,int target)
    {
        if(root==NULL) return;
        if(root->data==target) targetNode=root;
        if(root->left){
            mp[root->left]=root;
            dfs(root->left,mp,target);
        }
        
        if(root->right){
            mp[root->right]=root;
            dfs(root->right,mp,target);
        }
    }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> nodeToParent;
        nodeToParent[root]=NULL;
        dfs(root,nodeToParent,target);
        
        // for(auto it:nodeToParent){
        //     if(it.second){
        //         cout<<it.first->data<<" -> "<<it.second->data<<endl;
        //     }
        // }
        
        map<Node*,int> vis;
        queue<pair<Node*,int>> q; // <Node,dis>
        q.push({targetNode,0});
        vis[targetNode]=0;
        // find Distance using BFS...
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            if((it.first->left)!=NULL && vis.find(it.first->left)==vis.end()){
                vis[it.first->left]=it.second+1;
                q.push({it.first->left,it.second+1});
            }
            
            if((it.first->right)!=NULL && vis.find(it.first->right)==vis.end()){
                vis[it.first->right]=it.second+1;
                q.push({it.first->right,it.second+1});
            }
            
            if(nodeToParent[it.first]!=NULL && vis.find(nodeToParent[it.first])==vis.end()){
                vis[nodeToParent[it.first]]=it.second+1;
                q.push({nodeToParent[it.first],it.second+1});
            }
        }
        
        int ans=0;
        for(auto it:vis){
            ans=max(ans,it.second);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends