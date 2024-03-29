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
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    q.push({i,j,0});
                }
            }
        }
        
        while(!q.empty()){
            int x=q.front()[0];
            int y=q.front()[1];
            int dis=q.front()[2];
            q.pop();
            if(ans[x][y]!=-1) continue;
            ans[x][y]=dis;
            for(int k=0;k<4;k++){
                int newX=x+dx[k];
                int newY=y+dy[k];
                
                if(isValid(newX,newY,n,m) && ans[newX][newY]==-1){
                    q.push({newX,newY,dis+1});
                }
            }
        }
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends