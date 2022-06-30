class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size()&1){
            int med=nums[n/2];
            int ans=0;
            for(auto it:nums) ans+=abs(med-it);
            return ans;
        }else{
            int med1=nums[n/2-1];
            int ans1=0;
            for(auto it:nums) ans1+=abs(med1-it);
            int med2=nums[n/2];
            int ans2=0;
            for(auto it:nums) ans2+=abs(med2-it);
            
            return max(ans1,ans2);
        }
    }
};