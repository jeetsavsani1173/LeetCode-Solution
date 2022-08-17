class Solution {
public:
    int helper(int idx,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(amount==0) return 0;
        if(idx==coins.size()) return 1e6;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount]; 
        
        int take=INT_MAX;
        if(coins[idx]<=amount)
            take=1+helper(idx,coins,amount-coins[idx],dp);
        
        int non_take=helper(idx+1,coins,amount,dp);
        
        return dp[idx][amount]=min(take,non_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=helper(0,coins,amount,dp);
        return ans==1e6?-1:ans;
    }
};