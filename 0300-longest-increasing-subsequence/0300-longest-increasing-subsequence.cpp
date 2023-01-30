class Solution {
public:
    int helper(int curr,int prev,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(curr==nums.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        
        int yes=(prev==-1 || nums[prev]<nums[curr])?1+helper(curr+1,curr,nums,dp):0;
        int no=helper(curr+1,prev,nums,dp);
        
        return dp[curr][prev+1]=max(yes,no);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return helper(0,-1,nums,dp);
    }
};