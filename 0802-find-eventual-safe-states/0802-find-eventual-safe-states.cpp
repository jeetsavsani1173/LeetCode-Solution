class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &pathVis,vector<int> &check){
        vis[node]=1;
        pathVis[node]=1;
        for(auto child:adj[node]){
            if(!vis[child]){
                if(dfs(child,adj,vis,pathVis,check)){
                    check[child]=0;
                    return true;
                }
            }else if(pathVis[child]){
                check[child]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> check(n,0);
        
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,graph,vis,pathVis,check);
        }
        
        for(int i=0;i<n;i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};