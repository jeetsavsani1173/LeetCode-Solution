class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,vector<int> &nums,map<int,int> &mp,vector<int> &temp_ans)
    {
        if(idx==nums.size()){
            ans.push_back(temp_ans);
            return;
        }
        
        int freq=mp[nums[idx]];
        for(int i=0;i<=freq;i++)
        {
            int count=i;
            while(count--) temp_ans.push_back(nums[idx]);
            helper(idx+1,nums,mp,temp_ans);
            count=i;
            while(count--) temp_ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        vector<int> unique;
        for(auto it:mp) unique.push_back(it.first);
        
        vector<int> temp;
        helper(0,unique,mp,temp);
        return ans;
    }
};