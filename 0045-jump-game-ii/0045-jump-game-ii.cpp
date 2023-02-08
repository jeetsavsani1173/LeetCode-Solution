class Solution {
public:
    int helper(int idx,vector<int> &nums,vector<int> &dp)
    {
        if(idx==(nums.size()-1)) return 0;

        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX-1;
        for(int i=1;i<=nums[idx];i++)
        {
            if(idx+i<nums.size())
            {
                ans=min(ans,helper(idx+i,nums,dp));
            }
        }
        return dp[idx]=1+ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};