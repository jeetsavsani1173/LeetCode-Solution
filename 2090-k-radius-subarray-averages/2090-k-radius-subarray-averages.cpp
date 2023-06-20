class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        long long sum=0;
        int i=0;
        int j=0;
        while(j<nums.size() && j<=(2*k)){
            sum+=nums[j];
            j++;
        }
        if(j==nums.size() && j<=(2*k)){
            for(auto it:nums) ans.push_back(-1);
            return ans;
        }
        int idx=0;
        for(idx=0;idx<k;idx++) ans.push_back(-1);
        
        for(;j<nums.size();idx++,j++,i++){
            ans.push_back(sum/(2*k+1));
            sum-=nums[i];
            sum+=nums[j];
        }
        ans.push_back(sum/(2*k+1));
        idx++;
        for(;idx<nums.size();idx++) ans.push_back(-1);
        return ans;
    }
};