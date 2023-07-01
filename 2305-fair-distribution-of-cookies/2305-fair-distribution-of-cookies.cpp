class Solution {
public:
    void helper(int idx,vector<int> &nums,vector<int> &vect,int &ans)
    {
        if(idx==nums.size())
        {
            int mx=INT_MIN;
            for(auto it:vect)
                mx=max(mx,it);
            
            ans=min(ans,mx);
            return;
        }
        
        for(int i=0;i<vect.size();i++)
        {
            vect[i]+=nums[idx];
            helper(idx+1,nums,vect,ans);
            vect[i]-=nums[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> vect(k,0);
        int ans=INT_MAX;
        helper(0,cookies,vect,ans);
        return ans;
    }
};