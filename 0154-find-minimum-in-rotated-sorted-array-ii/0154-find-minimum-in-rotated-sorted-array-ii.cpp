class Solution {
public:// Tc -> O(logn) in avg case O(n) in worst case.. when all element of array are equal then we need go for linear search...
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=INT_MAX;
        
        while(l<=r){
            int mid=(r-l)/2+l;
            
            if(nums[mid]<nums[r]){ // right part sorted..
                r=mid-1;
            }else if(nums[mid]>nums[r]){ // left part sorted
                l=mid+1;
            }else{
                r--;
            }
            ans=min(ans,nums[mid]);
        }
        return ans;
    }
};