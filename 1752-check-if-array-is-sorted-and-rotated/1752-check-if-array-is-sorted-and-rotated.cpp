class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        if(nums[n-1]>nums[0]) cnt++;
        for(int i=1;i<n;i++) if(nums[i-1]>nums[i]) cnt++;
        if(cnt>=2) return false;
        return true;
    }
};