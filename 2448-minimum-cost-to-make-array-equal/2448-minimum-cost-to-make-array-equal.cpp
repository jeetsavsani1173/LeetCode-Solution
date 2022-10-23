class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> vpr;
        for(int i=0;i<nums.size();i++)
            vpr.push_back({nums[i],cost[i]});
        sort(vpr.begin(),vpr.end());
        long long sum=0;
        for(auto it:cost)
            sum+=it;
        
        int i=0;
        long long median,total=0;
        
        while(total<((sum+1)/2) && i<nums.size()){
            total=total+(1ll*vpr[i].second);
            median=vpr[i].first;
            i++;
        }
        
        // finding Weighted Median
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=(1ll*abs(median-1ll*nums[i])*(1ll*cost[i]));
        }
        return ans;
    }
};