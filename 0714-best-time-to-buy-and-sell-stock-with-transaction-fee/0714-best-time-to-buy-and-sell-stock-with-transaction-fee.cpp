class Solution {
public:
    int helper(int idx,int buy,int fee,vector<int> &prices,vector<vector<int>> &dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=0;
        if(buy){
            profit=max(helper(idx+1,0,fee,prices,dp)-prices[idx]-fee,helper(idx+1,1,fee,prices,dp));
        }else{
            profit=max(helper(idx+1,1,fee,prices,dp)+prices[idx],helper(idx+1,0,fee,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return helper(0,1,fee,prices,dp);
    }
};