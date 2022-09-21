class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto it:nums)
            if(it%2==0)
                sum+=it;
        
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int val=queries[i][0];
            int idx=queries[i][1];
            
            if(val&1 && nums[idx]&1){
                sum+=val;
                sum+=nums[idx];
            }else if(val%2==0 && nums[idx]%2==0){
                sum+=val;
            }else if(val&1 && nums[idx]%2==0){
                sum-=nums[idx];
            }
            nums[idx]+=val;
            ans.push_back(sum);
        }
        
        return ans;
    }
};