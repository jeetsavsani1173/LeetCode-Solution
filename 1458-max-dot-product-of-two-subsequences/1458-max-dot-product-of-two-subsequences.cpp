class Solution {
public:
    int helper(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        dp[i][j]=nums1[i]*nums2[j]+max(helper(i+1,j+1,nums1,nums2,dp),0);
        if(i+1<nums1.size()) dp[i][j]=max(dp[i][j],helper(i+1,j,nums1,nums2,dp));
        if(j+1<nums2.size()) dp[i][j]=max(dp[i][j],helper(i,j+1,nums1,nums2,dp));
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,INT_MIN));
        return helper(0,0,nums1,nums2,dp);
    }
};