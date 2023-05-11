class Solution {
public:
    int helper(int i,int j,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        if(nums1[i]==nums2[j]) ans=max(ans,1+helper(i+1,j+1,nums1,nums2,dp));
        ans=max(ans,max(helper(i,j+1,nums1,nums2,dp),helper(i+1,j,nums1,nums2,dp)));
        return dp[i][j]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return helper(0,0,nums1,nums2,dp);
    }
};