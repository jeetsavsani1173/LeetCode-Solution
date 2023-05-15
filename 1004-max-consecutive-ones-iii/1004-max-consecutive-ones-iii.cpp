class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0) count++;
            while(count>k){
                if(nums[left]==0) count--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};