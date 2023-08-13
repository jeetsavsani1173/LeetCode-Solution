class Solution {
public:
    bool helper(int idx,vector<int> &nums,vector<int> &dp){
        if(idx==nums.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        if(idx+1<nums.size() && nums[idx]==nums[idx+1]){
            if(helper(idx+2,nums,dp)) return dp[idx]=true;
            if(idx+2<nums.size() && nums[idx]==nums[idx+2]){
                if(helper(idx+3,nums,dp)) return dp[idx]=true;
            }
        }
        
        if(idx+2<nums.size() && nums[idx]==nums[idx+1]-1 && nums[idx]==nums[idx+2]-2){
            if(helper(idx+3,nums,dp)) return dp[idx]=true;
        }
        
        return dp[idx]=false;
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};