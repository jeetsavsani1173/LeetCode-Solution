//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    string moves;
    void dfs(int x,int y,pair<int,int> &base,vector<vector<int>> &grid,vector<vector<bool>> &vis,vector<pair<int,int>> &ans){
        vis[x][y]=true;
        
        for(int k=0;k<4;k++){
            int newX=x+dx[k];
            int newY=y+dy[k];
            
            if(newX>=0 && newY>=0 && newX<vis.size() && newY<vis[0].size() && !vis[newX][newY] && grid[newX][newY]==1){
                ans.push_back({newX-base.first,newY-base.second});
                dfs(newX,newY,base,grid,vis,ans);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        moves="URDL";
        set<vector<pair<int,int>>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vpr;
                    pair<int,int> base={i,j};
                    dfs(i,j,base,grid,vis,vpr);
                    ans.insert(vpr);
                }
            }
        }
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends