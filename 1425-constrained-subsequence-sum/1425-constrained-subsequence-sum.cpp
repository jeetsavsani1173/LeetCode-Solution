class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        multiset<int> window = {0};
        
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i] + *window.rbegin();
            window.insert(dp[i]);
            if(i >= k) window.erase(window.find(dp[i - k]));
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};