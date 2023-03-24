class Solution {
public:
    vector<pair<int,int>> graph[50005]; 
    void dfs(int node,vector<bool> &vis,int &ans){
        vis[node]=true;
        for(auto child:graph[node]){
            if(!vis[child.first]){
                ans+=child.second;
                dfs(child.first,vis,ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto it:connections){
            graph[it[0]].push_back({it[1],1});
            graph[it[1]].push_back({it[0],0});
        }
        
        vector<bool> vis(n+1,false);
        int ans=0;
        dfs(0,vis,ans);
        
        return ans;
    }
};