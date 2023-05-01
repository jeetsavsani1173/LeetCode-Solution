class Solution {
public:
    int merge(vector<int> &nums,vector<int> &temp,int l,int mid,int r)
    {
        int ans=0;
        int i=l,j=mid+1,k=l;
        
        for(i=l;i<=mid;i++){
            while(j<=r && nums[i]>(2ll*nums[j])){
                j++;
            }
            ans+=(j-(mid+1));
        }
        
        i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid) temp[k++]=nums[i++];
        while(j<=r) temp[k++]=nums[j++];
        
        for(i=l;i<=r;i++){
            nums[i]=temp[i];
        }
        
        return ans;
    }
    int mergeSort(vector<int> &nums,vector<int> &temp,int l,int r)
    {
        int inversionCnt=0;
        if(l<r){
            int mid=(r-l)/2+l;
            
            inversionCnt+=mergeSort(nums,temp,l,mid);
            inversionCnt+=mergeSort(nums,temp,mid+1,r);
            
            inversionCnt+=merge(nums,temp,l,mid,r);
        }
        
        return inversionCnt;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size(),0);
        return mergeSort(nums,temp,0,nums.size()-1);
    }
};