class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<long long,int> mp;
        mp[0]=1;
        long long ans=0;
        long long xr=0ll;
        for(auto it:nums){
            xr=xr^it;
            ans+=mp[xr];
            mp[xr]++;
        }
        return ans;
    }
};