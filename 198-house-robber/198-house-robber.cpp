class Solution {
public:
    int helper(int idx,vector<int> &nums,vector<int> &dp)
    {
        if(idx>=nums.size()) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        // lets rob Ith house..
        int first=nums[idx]+helper(idx+2,nums,dp);
        
        // lets leave Ith house..
        int second=helper(idx+1,nums,dp);
        
        return dp[idx]=max(first,second);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return helper(0,nums,dp);
    }
};