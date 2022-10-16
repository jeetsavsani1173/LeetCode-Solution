class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        vector<int> mn,mx;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK) mn.push_back(i);
            if(nums[i]==maxK) mx.push_back(i);
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK) continue;
            
            int l=i;
            while(i<nums.size() && nums[i]>=minK && nums[i]<=maxK)
                i++;
            i--;
            int last_idx=l-1;
            for(int j=l;j<=i;j++)
            {
                if(nums[j]==minK)
                {
                    int next_idx=lower_bound(mx.begin(),mx.end(),j)-mx.begin();
                    long long cnt1=j-last_idx;
                    if(next_idx==mx.size()) continue;
                    long long cnt2=i-mx[next_idx]+1;
                    if(cnt2>0)
                        ans+=(cnt1*cnt2);
                    last_idx=j;
                }
                else if(nums[j]==maxK)
                {
                    int next_idx=lower_bound(mn.begin(),mn.end(),j)-mn.begin();
                    long long cnt1=j-last_idx;
                    if(next_idx==mn.size()) continue;
                    long long cnt2=i-mn[next_idx]+1;
                    if(cnt2>0)
                        ans+=(cnt1*cnt2);
                    last_idx=j;
                }
            }
        }
        return ans;
    }
};