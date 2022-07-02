// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int ans;
    void dfs(int node,int d,vector<int> graph[])
    {
        if(node==d) ans++;
        
        for(auto it:graph[node])
            dfs(it,d,graph);
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<int> graph[20];
	    for(auto it:edges)
	    {
	        graph[it[0]].push_back(it[1]);
	    }
	    ans=0;
	    dfs(s,d,graph);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends