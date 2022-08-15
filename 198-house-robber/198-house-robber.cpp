class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        dp[0][n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            dp[0][i]=nums[i]+dp[1][i+1];
            dp[1][i]=max(dp[0][i+1],dp[1][i+1]);
        }
        return max(dp[0][0],dp[1][0]);
    }
};