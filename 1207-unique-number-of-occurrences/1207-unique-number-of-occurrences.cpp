class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto it:arr) mp[it]++;
        
        map<int,int> mp2;
        for(auto it:mp) mp2[it.second]++;
        
        return mp2.size()==mp.size();
    }
};