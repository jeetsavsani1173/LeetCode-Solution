class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans=0;
        int s=-1,e=-1;
        int start_idx=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0){
                if(cnt%2==0) ans=max(ans,i-start_idx);
                else{
                    if(e==-1){
                        ans=max(ans,max(i-s-1,s-start_idx));
                    }else{
                        ans=max(ans,(i-start_idx)-min(i-e,s-start_idx+1));
                    }
                }
                s=-1;
                e=-1;
                start_idx=i+1;
                cnt=0;
            }else if(nums[i]<0){
                cnt++;
                if(s!=-1) e=i;
                else s=i;
            }
        }
        int n=nums.size();
        if(cnt%2==0) ans=max(ans,n-start_idx);
        else{
            if(e==-1){
                ans=max(ans,max(n-s-1,s-start_idx));
            }else{
                ans=max(ans,(n-start_idx)-min(n-e,s-start_idx+1));
            }
        }
        return ans;
    }
};