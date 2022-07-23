class Solution {
public:
    void merge(vector<pair<int,int>> &nums,int l,int mid,int r,vector<int> &ans)
    {
        vector<pair<int,int>> temp;
        int i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i].first>nums[j].first){
                ans[nums[i].second]+=(r-j+1);
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=r){
            temp.push_back(nums[j++]);
        }
        
        for(i=l;i<=r;i++)
        {
            nums[i]=temp[i-l];
        }
    }
    void mergesort(vector<pair<int,int>> &nums,int l,int r,vector<int> &ans)
    {
        if(l>=r) return;
        int mid=l+(r-l)/2;
        mergesort(nums,l,mid,ans);
        mergesort(nums,mid+1,r,ans);
        merge(nums,l,mid,r,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<pair<int,int>> vpr;
        for(int i=0;i<nums.size();i++) vpr.push_back({nums[i],i});
        mergesort(vpr,0,nums.size()-1,ans);
        return ans;
    }
};