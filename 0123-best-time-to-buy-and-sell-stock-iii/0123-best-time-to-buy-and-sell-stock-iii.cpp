class Solution {
public:
    // int helper(int idx,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
    //     if(cap==0) return 0;
    //     if(idx==prices.size()) return 0;
    //     if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
    //     int profit=0;
    //     if(buy){
    //         profit=max(helper(idx+1,0,cap,prices,dp)-prices[idx]
    //                    ,helper(idx+1,1,cap,prices,dp));
    //     }else{
    //         profit=max(helper(idx+1,1,cap-1,prices,dp)+prices[idx]
    //                    ,helper(idx+1,0,cap,prices,dp));
    //     }
    //     return dp[idx][buy][cap]=profit;
    // }
    int dp[100001][3][2];
    int func(int i, int prev, vector<int> &arr, int cnt) {
        if(i == arr.size()) {
            return prev ? -1e6 : 0;
        }
        if(dp[i][cnt][prev] != -1) return dp[i][cnt][prev];
        
        int ans = func(i+1, prev, arr, cnt);
        if(cnt < 2 && prev == 0) {
           ans = max(ans, func(i+1, 1, arr, cnt+1) - arr[i]); 
        }
        else if(prev) ans = max(ans, arr[i] + func(i+1, 0, arr, cnt));
        
        return dp[i][cnt][prev] = ans;
    }
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return helper(0,1,2,prices,dp);
        memset(dp, -1, sizeof(dp));
        return func(0, 0, prices, 0);
    }
};