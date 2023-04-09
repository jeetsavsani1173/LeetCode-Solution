class Solution {
public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    bool isPossible(int x,int y,int n,int m)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0}); // <Effort,x,y>
        vector<vector<int>> vis(n,vector<int>(m,-1));
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            if(tp[1]==n-1 && tp[2]==m-1) return tp[0];
            if(vis[tp[1]][tp[2]]!=-1) continue;
            vis[tp[1]][tp[2]]=tp[0];
            for(int k=0;k<4;k++){
                int newX=tp[1]+dx[k];
                int newY=tp[2]+dy[k];
                
                if(isPossible(newX,newY,n,m)){
                    pq.push({max(tp[0],abs(heights[tp[1]][tp[2]]-heights[newX][newY])),newX,newY});
                }
            }
        }
        return 0;
    }
};