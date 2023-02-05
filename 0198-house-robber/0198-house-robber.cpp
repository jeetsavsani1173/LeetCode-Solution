class Solution {
public:
    int helper(int idx,vector<int> &nums,vector<int> &dp)
    {
        if(idx>=nums.size()) return 0;
        // if(idx==nums.size()-1) return nums[idx];

        if(dp[idx]!=-1) return dp[idx];
        // Take
        int take=nums[idx]+helper(idx+2,nums,dp);

        // Non-take
        int non_take=helper(idx+1,nums,dp);

        return dp[idx]=max(take,non_take);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return helper(0,nums,dp);
    }
};