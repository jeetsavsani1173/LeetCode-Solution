class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    bool check(int m,vector<vector<int>>& cells,int row,int col){
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<=m;i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        queue<vector<int>> q;
        for(int j=0;j<col;j++) 
            if(grid[0][j]==0) {
                q.push({0,j});
                vis[0][j]=true;
            }
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it[0]==row-1) return true;
            for(int k=0;k<4;k++){
                int newX=it[0]+dx[k];
                int newY=it[1]+dy[k];
                
                if(newX>=0 && newX<row && newY>=0 && newY<col && grid[newX][newY]==0 && !vis[newX][newY]){
                    q.push({newX,newY});
                    vis[newX][newY]=true;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int low=0,high=cells.size()-1;
        
        while(low<=high){
            int mid=(high-low)/2+low;
            if(check(mid,cells,row,col)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return 1+ans;
    }
};