class Solution {
public:
    int find_maximum_length_subarray_with_sum_equal_target(vector<int> &nums,int target)
    {
        int ans=INT_MIN;
        map<int,int> mp;
        mp[0]=-1;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            
            if(mp.find(curr_sum-target)!=mp.end())
            {
                int left=mp[curr_sum-target];
                int right=i;
                
                ans=max(ans,right-left);
            }
            mp[curr_sum]=i;
        }
        return ans;
    }
    int minOperations(vector<int>& nums, int x) {
        int total_sum=0;
        for(auto it:nums) total_sum+=it;
        
        int target=total_sum-x;
        int ans=find_maximum_length_subarray_with_sum_equal_target(nums,target);
        if(target==0) return nums.size();
        return ans==INT_MIN?-1:nums.size()-ans;
    }
};