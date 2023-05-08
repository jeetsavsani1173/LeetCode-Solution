class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1;
        
        while(start<=end){
            int mid=(end-start)/2+start;
            
            long lval=(mid>0)?nums[mid-1]:LONG_MIN;
            long rval=(mid<(n-1))?nums[mid+1]:LONG_MIN;
            
            if(nums[mid]>lval && nums[mid]>rval){
                return mid;
            }else if(lval<nums[mid] && nums[mid]<rval){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return 0;
    }
};