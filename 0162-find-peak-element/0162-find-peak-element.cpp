class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int start=0,end=n-1;
        
        while(start<=end){
            int mid=(end-start)/2+start;
            
            int lval=(mid>0)?nums[mid-1]:INT_MIN;
            int rval=(mid<(n-1))?nums[mid+1]:INT_MIN;
            
            if(nums[mid]>lval && nums[mid]>rval){
                return mid;
            }else if(lval<nums[mid] && nums[mid]<rval){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        
        return (nums[0]>nums[1])?0:(n-1);
    }
};