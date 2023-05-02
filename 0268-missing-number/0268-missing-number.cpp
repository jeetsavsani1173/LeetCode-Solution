class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i,xr=0;
        for(i=0;i<nums.size();i++)
            xr=xr^(i+1)^nums[i];
        
        return xr;
    }
};