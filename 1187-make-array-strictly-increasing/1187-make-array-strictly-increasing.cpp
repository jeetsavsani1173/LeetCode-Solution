class Solution {
public:
    int helper(int idx,int prev,vector<int>& arr1, vector<int>& arr2,map<pair<int,int>,int> &dp){
        if(idx==arr1.size()) return 0;
        if(dp.find({idx,prev})!=dp.end()) return dp[{idx,prev}];
        int index=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        
        int ans=INT_MAX/2;
        if(prev<arr1[idx]) 
            ans=min(ans,helper(idx+1,arr1[idx],arr1,arr2,dp));
        if(index<arr2.size()) 
            ans=min(ans,1+helper(idx+1,arr2[index],arr1,arr2,dp));
        
        return dp[{idx,prev}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> dp;
        int ans=helper(0,-1,arr1,arr2,dp);
        return ans>=INT_MAX/4?-1:ans;
    }
};