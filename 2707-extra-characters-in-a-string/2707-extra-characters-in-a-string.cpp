class Solution {
public:
    int helper(int idx,string &s,map<string,int> &mp,vector<int> &dp){
        if(idx==s.size()) return 0;
        if(dp[idx]!=-1) return dp[idx]; 
        int ans=100;
        for(int i=idx+1;i<=s.size();i++){
            string tmp=s.substr(idx,i-idx);
            if(mp.find(tmp)!=mp.end()) ans=min(ans,helper(i,s,mp,dp));
            else ans=min(ans,(i-idx)+helper(i,s,mp,dp));
        }
        return dp[idx]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int> mp;
        for(auto it:dictionary) mp[it]++;
        vector<int> dp(s.size()+1,-1);
        return helper(0,s,mp,dp);
    }
};