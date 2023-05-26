class Solution {
public:
    int helper(int idx,int m,vector<int> &piles,vector<vector<int>> &dp){
        if(idx>=piles.size()) return 0;
        if(dp[idx][m]!=-1) return dp[idx][m];
        int ans=INT_MIN;
        int sum=0;
        for(int j=0;j<2*m;j++){
            if(idx+j<piles.size()) sum+=piles[idx+j];
            
            ans=max(ans,sum-helper(idx+j+1,max(m,j+1),piles,dp));
        }
        return dp[idx][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int aMinusB=helper(0,1,piles,dp);
        int aPulusB=0;
        for(auto it:piles) aPulusB+=it;
        return (aPulusB+aMinusB)/2;
    }
};