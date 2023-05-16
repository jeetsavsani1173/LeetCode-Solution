class Solution {
public:
    // Exact (k) = atmost(k)- atmost(k-1)
    int atMost(vector<int> &nums,int k){
        int ans=0;
        int left=0;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            
            while(left<=right && sum>k){
                sum-=nums[left];
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};