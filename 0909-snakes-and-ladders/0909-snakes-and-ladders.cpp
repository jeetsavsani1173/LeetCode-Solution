class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int level=0,cell=1;
        vector<int> vect;
        vect.push_back(0);
        
        for(int i=n-1;i>=0;i--)
        {
            if(level%2==0){
                for(int j=0;j<n;j++){
                    if(board[i][j]==-1) vect.push_back(cell);
                    else vect.push_back(board[i][j]);
                    cell++;
                }
            }else{
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]==-1) vect.push_back(cell);
                    else vect.push_back(board[i][j]);
                    cell++;
                }
            }
            level++;
        }
        
        // Generate a Graph from grid
        vector<int> graph[n*n+1];
        for(cell=1;cell<=n*n;cell++)
        {
            for(int move=1;move<=6 && cell+move<=(n*n);move++){
                if(cell==vect[cell+move]) continue;
                graph[cell].push_back(vect[cell+move]);
            }
        }
        // Apply BFS 
        vector<int> vis(n*n+1,-1);
        queue<pair<int,int>> q;
        q.push({1,0});
        
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(vis[node]!=-1) continue;
            vis[node]=dis;
            for(auto it:graph[node]){
                if(vis[it]==-1){
                    q.push({it,dis+1});
                }
            }
        }
        return vis[n*n];
    }
};