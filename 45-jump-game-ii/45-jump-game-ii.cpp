class Solution {
public:
    int helper(int idx,vector<int> &nums,vector<int> &dp)
    {
        if(idx==nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX-1;
        for(int jump=1;jump<=nums[idx];jump++){
            if(idx+jump<nums.size())
                ans=min(ans,helper(idx+jump,nums,dp));
        }
        return dp[idx]=ans+1;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};