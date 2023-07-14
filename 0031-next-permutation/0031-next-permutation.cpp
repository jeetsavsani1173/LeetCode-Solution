class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=nums.size()-2;
        while(idx>=0){
            if(nums[idx]<nums[idx+1]) break;
            idx--;
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int i;
        for(i=nums.size()-1;i>=0;i--){
            if(nums[idx]<nums[i]){
                break;
            }
        }
        swap(nums[idx],nums[i]);
        i=nums.size()-1;
        idx++;
        while(idx<=i){
            swap(nums[idx],nums[i]);
            idx++;
            i--;
        }
    }
};