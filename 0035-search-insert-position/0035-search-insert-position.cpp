class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,ans=nums.size();
        
        while(l<=r){
            int mid=(r-l)/2+l;
            
            if(nums[mid]>=target){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};