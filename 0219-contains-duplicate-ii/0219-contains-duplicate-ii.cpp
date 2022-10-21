class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<long>> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        bool ans=false;
        for(auto it:mp)
        {
            for(int i=0;i+1<it.second.size();i++)
            {
                if((it.second[i+1]-it.second[i])<=k) ans=true;
            }
        }
        return ans;
    }
};