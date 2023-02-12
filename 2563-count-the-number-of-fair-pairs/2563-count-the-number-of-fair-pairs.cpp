class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0ll;
        for(int i=0;i<nums.size();i++)
        {
            auto it1=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto it2=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            ans+=(it2-it1);
        }
        return ans;
    }
};