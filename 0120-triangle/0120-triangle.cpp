class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp=triangle;
        
        for(int i=1;i<triangle.size();i++)
        {
            dp[i][0]+=dp[i-1][0];
            for(int j=1;j<triangle[i].size()-1;j++)
            {
                dp[i][j]+=min(dp[i-1][j],dp[i-1][j-1]);
            }
            dp[i][triangle[i].size()-1]+=dp[i-1][triangle[i].size()-2];
        }
        int ans=INT_MAX;
        for(int j=0;j<dp[n-1].size();j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};