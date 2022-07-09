class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(),INT_MIN);
        multiset<int> pq;
        dp[0]=nums[0];
        pq.insert(dp[0]);
        for(int i=1;i<nums.size();i++){
            if(pq.size()>k){
                auto it=pq.find(dp[i-k-1]);
                pq.erase(it);
            }
            dp[i]=max(dp[i],nums[i]+(*pq.rbegin()));
            pq.insert(dp[i]);
        }
        return dp[nums.size()-1];
    }
};