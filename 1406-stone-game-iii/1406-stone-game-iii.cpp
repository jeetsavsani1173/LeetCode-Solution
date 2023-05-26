class Solution {
public:
    int helper(int idx,vector<int> &stone,vector<int> &dp){
        if(idx>=stone.size()) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MIN;
        if(idx<stone.size()) ans=max(ans,stone[idx]-helper(idx+1,stone,dp));
        if(idx+1<stone.size()) ans=max(ans,stone[idx]+stone[idx+1]-helper(idx+2,stone,dp));
        if(idx+2<stone.size()) ans=max(ans,stone[idx]+stone[idx+1]+stone[idx+2]-helper(idx+3,stone,dp));
        
        return dp[idx]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1,-1);
        int ans=helper(0,stoneValue,dp);
        if(ans==0) return "Tie";
        else if(ans<0) return "Bob";
        else return "Alice";
    }
};