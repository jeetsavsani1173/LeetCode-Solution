class Solution {
public:
    bool helper(int idx,string &s,unordered_map<string,int> &mp,vector<int> &dp)
    {
        if(idx==s.size()){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++){
            if(mp[s.substr(idx,i-idx+1)]!=0){
                if(helper(i+1,s,mp,dp)==true) return true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto it:wordDict) mp[it]++;
        vector<int> dp(s.size()+1,-1);
        return helper(0,s,mp,dp);
    }
};