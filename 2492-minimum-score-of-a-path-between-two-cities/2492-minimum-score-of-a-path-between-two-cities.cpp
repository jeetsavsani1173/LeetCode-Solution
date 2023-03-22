class Solution {
public:
    vector<pair<int,int>> graph[100005];
    void dfs(int node,vector<bool> &vis){
        vis[node]=true;
        
        for(auto it:graph[node]){
            if(!vis[it.first])
                dfs(it.first,vis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        for(auto it:roads){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        vector<bool> vis(n+1,false);
        dfs(1,vis);
        
        int mini_path = INT_MAX;
        for(int i=0; i<roads.size(); i++)
        {
            if(vis[roads[i][0]] && vis[roads[i][1]] && roads[i][2] < mini_path)
                mini_path = roads[i][2];
        }
        return mini_path;
    }
};