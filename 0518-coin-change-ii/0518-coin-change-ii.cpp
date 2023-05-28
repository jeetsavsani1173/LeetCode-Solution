class Solution {
public:
int helper(int idx,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(idx==coins.size()) return 0;

        if(dp[idx][amount]!=-1) return dp[idx][amount];
        // Take
        int Take=helper(idx,coins,amount-coins[idx],dp);

        // Non-Take
        int NonTake=helper(idx+1,coins,amount,dp);

        return dp[idx][amount]=(Take+NonTake);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=helper(0,coins,amount,dp);
        return ans==INT_MAX-1?-1:ans;
    }
};