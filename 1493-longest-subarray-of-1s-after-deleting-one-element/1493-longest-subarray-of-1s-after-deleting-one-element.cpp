class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>> vpr;
        
        int count=1;
        int currEle=nums[0];
        for(int i=1;i<nums.size();i++){
            if(currEle==nums[i]) count++;
            else{
                vpr.push_back({currEle,count});
                count=1;
                currEle=nums[i];
            }
        }
        vpr.push_back({currEle,count});
        // for(auto it:vpr) cout<<it.first<<" "<<it.second<<endl;
        if(vpr.size()==1 && vpr[0].first==1) return vpr[0].second-1;
        int ans=0;
        for(int i=0;i<vpr.size();i++){
            if(vpr[i].first==0 && vpr[i].second==1){
                int left=(i>=1)?(vpr[i-1].second):0;
                int right=(i<vpr.size()-1)?(vpr[i+1].second):0;
                
                ans=max(ans,left+right);
            }else if(vpr[i].first==1){
                ans=max(ans,vpr[i].second);
            }
        }
        return ans;
    }
};