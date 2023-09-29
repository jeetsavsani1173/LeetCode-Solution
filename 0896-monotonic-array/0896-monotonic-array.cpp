class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                cnt1++;
            }else if(nums[i-1]>nums[i]){
                cnt2++;
            }
        }
        
        if(cnt1==0 || cnt2==0){
            return true;
        }
        return false;
    }
};