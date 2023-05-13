class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int M=1e9+7;
        int n=max(low,high);
        vector<vector<long>> dp(2,vector<long>(n+1,0));
        dp[0][0]=1;
        
        for(int j=1;j<=n;j++){
            dp[0][j]=(j>=zero)?(dp[0][j-zero]+dp[1][j-zero])%M:0;
            dp[1][j]=(j>=one)?(dp[0][j-one]+dp[1][j-one])%M:0;
        }
        int ans=0;
        for(int j=low;j<=high;j++){
            ans=(ans%M+dp[0][j]%M)%M;
            ans=(ans%M+dp[1][j]%M)%M;
        }
        return ans;
    }
};