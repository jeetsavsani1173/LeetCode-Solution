class Solution {
public: // Tc : O(NlogN) Sc : O(1) using sorting + two pointer
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vpr;
        for(int i=0;i<nums.size();i++)
            vpr.push_back({nums[i],i});
        
        sort(vpr.begin(),vpr.end());
        
        int i=0,j=nums.size()-1;
        
        while(i<j)
        {
            if(vpr[i].first+vpr[j].first==target)
                return {vpr[i].second,vpr[j].second};
            else if(vpr[i].first+vpr[j].first > target)
                j--;
            else
                i++;
        }
        return {};
    }
};