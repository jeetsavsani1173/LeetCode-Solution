class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=INT_MAX;
        
        while(l<=r){
            int mid=(r-l)/2+l;
            
            if(nums[mid]<nums[r]){ // right part sorted..
                r=mid-1;
            }else{ // left part sorted
                l=mid+1;
            }
            ans=min(ans,nums[mid]);
        }
        return ans;
    }
};