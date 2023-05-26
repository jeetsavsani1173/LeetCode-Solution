class Solution {
public:
    int helper(int i,int j,vector<int> &p,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(p[i]+helper(i+1,j,p,dp),p[j]+helper(i,j-1,p,dp));
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,n-1,piles,dp)>0;
    }
};