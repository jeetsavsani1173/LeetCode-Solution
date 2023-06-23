class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>> dp(nums.size()+1);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                dp[i][diff]=dp[j].count(diff) > 0 ? 1 + dp[j][diff] : 2;
                ans=max(ans,dp[i][diff]);
            }
        }
        // for(auto it1:vm){
        //     // map<int,int> tmp=it1.second;
        //     for(auto it:it1) ans=max(ans,it.second);
        // }
        return ans;
    }
};