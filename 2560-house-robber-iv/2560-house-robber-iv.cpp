class Solution {
public:
    bool isposiible(int temp_ans,vector<int> &nums,int k)
    {
        int cnt=0;
        for(int i=0;i<nums.size();)
        {
            if(nums[i]<=temp_ans){
                cnt++;
                i+=2;
            }else{
                i++;
            }
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        
        int ans=INT_MAX;
        int l=mn,r=mx;
        while(l<=r){
            int mid=(r-l)/2+l;
            
            if(isposiible(mid,nums,k)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};