class Solution {
public:
    int helper(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(i-1>=0)
            ans=min(ans,grid[i][j]+helper(i-1,j,grid,dp));
        if(j-1>=0)
            ans=min(ans,grid[i][j]+helper(i,j-1,grid,dp));
        return dp[i][j]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,grid,dp);
    }
};