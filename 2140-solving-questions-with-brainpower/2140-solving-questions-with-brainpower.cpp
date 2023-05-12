class Solution {
public:
    long long helper(int idx,vector<vector<int>>& questions,vector<long long> &dp)
    {
        if(idx>=questions.size()) return 0ll;
        if(dp[idx]!=-1) return dp[idx];
        long long take=questions[idx][0]+helper(idx+questions[idx][1]+1,questions,dp);
        long long nonTake=helper(idx+1,questions,dp);
        return dp[idx]=max(take,nonTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1,-1);
        return helper(0,questions,dp);
    }
};