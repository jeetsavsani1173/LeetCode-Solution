class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        
        int ans=0;
        
        while(mp.size()>0){
            int curr=mp.begin()->first;
            for(int i=curr;i<curr+k;i++){
                if(mp[i]>0){
                    mp[i]--;
                    if(mp[i]==0) mp.erase(i);
                }else{
                    return false;
                }
            }
            ans++;
        }
        return ans;
    }
};