class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ansP=0,prev=-200;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==prev){
                continue;
            }else{
                prev=nums[i];
                nums[ansP++]=prev;
            }
        }
        return ansP;
    }
};