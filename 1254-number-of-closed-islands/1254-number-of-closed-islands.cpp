class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    void dfs1(int x,int y,vector<vector<int>> &grid)
    {
        grid[x][y]=1;
        for(int k=0;k<4;k++)
        {
            int newX=x+dx[k];
            int newY=y+dy[k];
            
            if(newX>=0 && newY>=0 && newX<grid.size() && newY<grid[0].size() && grid[newX][newY]==0)
                dfs1(newX,newY,grid);
        }
    }
    void makeAllCornerVis(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        
        // first row
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                dfs1(0,j,grid);
            }
        }
        // last row
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==0){
                dfs1(n-1,j,grid);
            }
        }
        
        // first col
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                dfs1(i,0,grid);
            }
        }
        
        // last col
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==0){
                dfs1(i,m-1,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        makeAllCornerVis(grid);
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs1(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};