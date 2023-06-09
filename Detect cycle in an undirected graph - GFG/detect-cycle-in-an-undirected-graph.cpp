//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int par,vector<int> graph[],vector<bool> &vis)
    {
        vis[node]=true;
        for(auto it:graph[node])
        {
            if(it==par) continue;
            if(vis[it]) return true;
            if(dfs(it,node,graph,vis)) return true;
        }
        return false;
    }
    
    bool bfs(int nd,vector<int> graph[],vector<bool> &vis)
    {
        queue<pair<int,int>> q;
        vis[nd]=true;
        q.push({nd,-1});
        
        while(!q.empty())
        {
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            // vis[node]=true;
            for(auto it:graph[node])
            {
                if(it==par) continue;
                if(vis[it]) return true;
                q.push({it,node});
                vis[it]=true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // DFS
        // vector<bool> vis(V,false);
        // for(int i=0;i<V;i++){
        //     if(!vis[i]) 
        //         if(dfs(i,-1,adj,vis)) return true;
        // }
        // return false;
        
        // BFS
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]) 
                if(bfs(i,adj,vis)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends