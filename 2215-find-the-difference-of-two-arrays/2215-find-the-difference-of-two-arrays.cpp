class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1,mp2;
        for(auto it:nums1) mp1[it]++;
        for(auto it:nums2) mp2[it]++;
        
        set<int> st1;
        for(auto it:nums1){
            if(mp2[it]==0){
                st1.insert(it);
            }
        }
        
        set<int> st2;
        for(auto it:nums2){
            if(mp1[it]==0){
                st2.insert(it);
            }
        }
        
        vector<int> ans1,ans2;
        for(auto it:st1) ans1.push_back(it);
        for(auto it:st2) ans2.push_back(it);
        
        return {ans1,ans2};
    }
};