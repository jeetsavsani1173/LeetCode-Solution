class Solution {
public:
    bool isPoss(vector<int> &nums,int diff,int p){
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=diff){
                p--;
                i++;
            }
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        int ans=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            
            if(isPoss(nums,mid,p)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};