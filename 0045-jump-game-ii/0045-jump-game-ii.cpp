class Solution {
public:
    int helper(int idx,vector<int> &nums,vector<int> &dp){
        if(idx>=(nums.size()-1)) return 0;
        
        int ans=INT_MAX-1;
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=1;i<=nums[idx];i++){
            ans=min(ans,1+helper(idx+i,nums,dp));
        }
        
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return helper(0,nums,dp);
    }
};