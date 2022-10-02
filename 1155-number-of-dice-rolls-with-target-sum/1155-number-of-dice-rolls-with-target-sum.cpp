class Solution {
public:
    int M;
    int helper(int idx,int n,int k,int sum,int target,vector<vector<int>> &dp)
    {
        if(sum==target && idx==n+1)
            return 1;
        else if(sum==target || idx==n+1)
            return 0;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int count=0;
        for(int i=1;i<=k;i++)
        {
            if(sum+i<=target)
                count=((count%M)+(helper(idx+1,n,k,sum+i,target,dp)%M))%M;
        }
        return dp[idx][sum]=count;
    }
    int numRollsToTarget(int n, int k, int target) {
        M=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return helper(1,n,k,0,target,dp);
    }
};