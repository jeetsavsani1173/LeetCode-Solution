class Solution {
public:
    void dfs(int node,int color,vector<vector<int>> &graph,vector<int> &vis){
        vis[node]=color;
        for(auto it:graph[node]){
            if(vis[it]==-1)
                dfs(it,color^1,graph,vis);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1) dfs(i,0,graph,vis);
        }
        
        for(int i=0;i<graph.size();i++)
        {
            for(auto it:graph[i]){
                if(vis[it]==vis[i]) return false;
            }
        }
        return true;
    }
};