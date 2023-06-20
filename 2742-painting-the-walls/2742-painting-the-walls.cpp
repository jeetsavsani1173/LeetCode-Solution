class Solution {
public:
    int helper(int idx,int wallRemain,vector<int>& cost, vector<int>& time,vector<vector<int>> &dp){
        if(wallRemain<=0) return 0;
        if(idx>=cost.size()) return 2000000000;
        if(dp[idx][wallRemain]!=-1) return dp[idx][wallRemain];
        
        int take=cost[idx]+helper(idx+1,wallRemain-time[idx]-1,cost,time,dp);
        int nonTake=helper(idx+1,wallRemain,cost,time,dp);
        
        return dp[idx][wallRemain]=min(take,nonTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return helper(0,n,cost,time,dp);
    }
};