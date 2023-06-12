class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        if(n==0)
            return res;
        for(int i=0;i<n;)
        {
            int start=i,end=i;
            while(end+1<n && nums[end+1]==nums[end]+1)
                end++;
            
            if(start==end)
                res.push_back(to_string(nums[start]));
            else if(end>start)
            {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            i=end+1;
        }
        return res;
    }
};