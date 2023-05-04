class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<=1) return n;
        int ans=1;
        int cnt=1;
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1){
                cnt++;
            }else{
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};