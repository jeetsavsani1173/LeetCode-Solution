class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        vector<pair<int,int>> vpr;
        
        for(auto it:mp)
            vpr.push_back({it.second,it.first});
        
        sort(vpr.begin(),vpr.end());
        reverse(vpr.begin(),vpr.end());
        
        vector<int> ans;
        int i=0;
        while(k--){
            ans.push_back(vpr[i].second);
            i++;
        }
        return ans;
    }
};