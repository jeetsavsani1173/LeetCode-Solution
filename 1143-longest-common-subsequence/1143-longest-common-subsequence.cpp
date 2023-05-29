class Solution {
public:
    int helper(int idx1,int idx2,string &s1,string &s2,vector<vector<int>> &dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2]; 
        if(s1[idx1]==s2[idx2]) 
            return dp[idx1][idx2]=1+helper(idx1-1,idx2-1,s1,s2,dp);
        else
            return dp[idx1][idx2]=max(helper(idx1-1,idx2,s1,s2,dp),helper(idx1,idx2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,s1,s2,dp);
    }
};