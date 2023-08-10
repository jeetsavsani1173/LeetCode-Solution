class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int currSum=0;
        for(auto it:nums){
            currSum+=it;
            ans=max(ans,currSum);
            if(currSum<0) currSum=0;
        }
        return ans;
    }
};