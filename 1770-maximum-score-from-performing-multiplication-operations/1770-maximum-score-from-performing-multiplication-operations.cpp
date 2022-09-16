class Solution {
public:
    int ans;
    int helper(int idx,vector<int> &mul,int start,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(idx==mul.size()){
            return 0;
        }
        
        if(dp[idx][start]!=INT_MIN) return dp[idx][start];
        
        int end=nums.size()-(idx-start)-1;
        // take from left
        int left=mul[idx]*nums[start]+helper(idx+1,mul,start+1,nums,dp);
        
        //take form right..
        int right=mul[idx]*nums[end]+helper(idx+1,mul,start,nums,dp);
        
        return dp[idx][start]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        ans=INT_MIN;
        vector<vector<int>> dp(1001,vector<int>(1001,INT_MIN));
        return helper(0,multipliers,0,nums,dp);
    }
};