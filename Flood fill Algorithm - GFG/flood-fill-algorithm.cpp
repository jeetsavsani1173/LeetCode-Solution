//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    bool issafe(int x,int y,int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void dfs(int r,int c,int n,int m,vector<vector<int>>& image,vector<vector<bool>> &vis,int color,int newColor)
    {
        vis[r][c]=true;
        image[r][c]=newColor;
        for(int i=0;i<4;i++)
        {
            int newX=r+dx[i];
            int newY=c+dy[i];
            
            if(issafe(newX,newY,n,m) && !vis[newX][newY] && image[newX][newY]==color)
                dfs(newX,newY,n,m,image,vis,color,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size(),m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(sr,sc,n,m,image,vis,image[sr][sc],newColor);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends