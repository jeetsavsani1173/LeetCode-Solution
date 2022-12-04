class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long total=0;
        for(auto it:nums) total+=it;
        
        long left=0,right=total;
        long mn=LONG_MAX;
        long idx=0;
        for(int i=0;i<nums.size();i++)
        {
            left+=nums[i];
            right-=nums[i];
            long temp;
            if(i==nums.size()-1)
                temp=(left*1ll/(i+1));
            else
                temp=(left*1ll/(i+1))-(right*1ll/(nums.size()-i-1));
            if(abs(temp)<mn)
            {
                mn=abs(temp);
                idx=i;
            }
        }
        return idx;
    }
};