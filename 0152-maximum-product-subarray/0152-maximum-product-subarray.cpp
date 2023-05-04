class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=*max_element(nums.begin(),nums.end());
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        dp[0][0]=1;
        dp[1][0]=1;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                dp[0][i+1]=1;
                dp[1][i+1]=1;
                continue;
            }
            dp[0][i+1]=max(nums[i],max(nums[i]*dp[0][i],nums[i]*dp[1][i]));
            dp[1][i+1]=min(nums[i],min(nums[i]*dp[0][i],nums[i]*dp[1][i]));
            ans=max(ans,dp[0][i+1]);
        }
        return ans;
    }
};