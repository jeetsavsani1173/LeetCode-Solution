class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        map<int,int> mp;
        
        for(auto it:nums){
            if(mp.find(it-diff)==mp.end()){
                mp[it]=1;
            }else{
                mp[it]=mp[it-diff]+1;
            }
        }
        int ans=0;
        for(auto it:mp) ans=max(ans,it.second);
        return ans;
    }
};