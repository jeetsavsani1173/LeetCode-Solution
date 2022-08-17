class Solution {
public:
    int helper(vector<int>& coins, int amount,vector<int> &dp)
    {
        if(amount<0) return INT_MAX;
        if(amount==0) return 0;
        
        if(dp[amount]!=-1) return dp[amount];
        
        int ans=INT_MAX-1;
        for(int i=0;i<coins.size();i++)
        {
            ans=min(ans,helper(coins,amount-coins[i],dp));
        }
        
        return dp[amount]=1+ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=helper(coins,amount,dp);
        return ans==INT_MAX?-1:ans;
    }
};