class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,1);
        vector<int> hash(n+1,-1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        
        int maxi=0;
        for(auto it:dp) maxi=max(maxi,it);
        
        int idx=n-1;
        while(dp[idx]!=maxi){
            idx--;
        }
        
        vector<int> ans;
        while(idx!=-1){
            ans.push_back(nums[idx]);
            idx=hash[idx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};