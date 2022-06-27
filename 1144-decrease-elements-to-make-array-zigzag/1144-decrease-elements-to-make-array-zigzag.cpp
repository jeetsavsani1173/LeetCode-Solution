class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans1=0;
        // check for even index maximum..
        for(int i=1;i<nums.size();i+=2)
        {
            int lval=(i==0)?INT_MAX:(nums[i-1]);
            int rval=(i==nums.size()-1)?INT_MAX:(nums[i+1]);
            
            if(nums[i]>=min(lval,rval)){
                ans1+=(abs(nums[i]-min(lval,rval)));
                ans1++;
            }
        }
        
        int ans2=0;
        // check for odd index maximum..
        for(int i=0;i<nums.size();i+=2)
        {
            int lval=(i==0)?INT_MAX:(nums[i-1]);
            int rval=(i==nums.size()-1)?INT_MAX:(nums[i+1]);
            
            if(nums[i]>=min(lval,rval)){
                ans2+=(abs(nums[i]-min(lval,rval)));
                ans2++;
            }
        }

        return min(ans1,ans2);
    }
};