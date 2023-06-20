class Solution {
public:
    int M=1e9+7;
    int helper(int idx,int prev_idx,vector<int> &nums,int mask,vector<vector<int>> &dp){
        if(idx==nums.size()) return 1;
        
        if(dp[prev_idx+1][mask]!=-1) return dp[prev_idx+1][mask];
        int ans=0;
        for(int j=0;j<nums.size();j++){
            if((mask&(1<<j))>0) continue;
            
            if(prev_idx==-1 || nums[j]%nums[prev_idx]==0 || nums[prev_idx]%nums[j]==0)
                ans=(ans%M+helper(idx+1,j,nums,mask|(1<<j),dp)%M)%M;
        }
        return dp[prev_idx+1][mask]=ans;
    }
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        M=1e9+7;
        vector<vector<int>> dp(n+2,vector<int>(1<<15,-1));
        return helper(0,-1,nums,0,dp);
    }
};