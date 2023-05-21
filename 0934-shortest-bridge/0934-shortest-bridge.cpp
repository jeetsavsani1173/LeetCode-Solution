class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    bool isValid(int x,int y,vector<vector<int>> &grid){
        int n=grid.size(),m=grid[0].size();
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newX=i+dx[k];
            int newY=j+dy[k];
            
            if(isValid(newX,newY,grid) && !vis[newX][newY] && grid[newX][newY]==1){
                dfs(newX,newY,grid,vis);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        } 
        // for(auto it:vis){
        //     for(auto it1:it) {
        //         cout<<it1<<" ";
        //     }cout<<endl;
        // }
        
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]){
                    q.push({i,j,0});
                }
            }
        }
        vector<vector<int>> vist(n,vector<int>(m,-1));
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(vist[it[0]][it[1]]!=-1) continue;
            vist[it[0]][it[1]]=it[2];
            if(grid[it[0]][it[1]]==1 && it[2]!=0) return it[2]-1;
            for(int k=0;k<4;k++){
                int newX=it[0]+dx[k];
                int newY=it[1]+dy[k];
                
                if(isValid(newX,newY,grid) && vist[newX][newY]==-1){
                    q.push({newX,newY,1+it[2]});
                }
            }
        }
        return -1;
    }
};