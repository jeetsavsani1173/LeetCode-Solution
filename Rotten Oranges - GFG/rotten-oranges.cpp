//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    bool isValid(int x,int y,int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<vector<int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
                if(grid[i][j]==2)
                    q.push({i,j,0});
            }
        }
        if(q.size()==0 && cnt!=0) return -1;
        
        while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            int dis=q.front()[2];
            q.pop();
            if(vis[x][y]!=-1) continue;
            vis[x][y]=dis;
            for(int k=0;k<4;k++)
            {
                int newX=x+dx[k];
                int newY=y+dy[k];
                
                if(isValid(newX,newY,n,m) && grid[newX][newY]==1)
                    q.push({newX,newY,dis+1});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==-1) return -1;
            }
        }
        int ans=0;
        for(auto it:vis)
            for(auto it1:it)
                ans=max(ans,it1);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends