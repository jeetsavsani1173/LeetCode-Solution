class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i=0,j=nums.size()/2;
        for(i=0,j=nums.size()/2;i<nums.size()/2;i++,j++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        
        return ans;
    }
};