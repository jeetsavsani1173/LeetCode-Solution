//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    vector<int> graph[10005];
    vector<int> bfs(vector<vector<int>>& prerequisites,int n)
    {
        vector<int> indeg(n,0);
        for(auto it:prerequisites)
        {
            indeg[it[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++)
            if(indeg[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:graph[node])
            {
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        
        if(ans.size()==n) return ans;
        return {};
    }
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        for(auto it:prerequisites)
            graph[it[1]].push_back(it[0]);
        
        // bfs
        vector<int> ans= bfs(prerequisites,n);
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends