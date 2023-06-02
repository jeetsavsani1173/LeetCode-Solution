//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long helper(int idx,int buy,int fee,vector<long long> &prices,vector<vector<long long>> &dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        long long profit=0;
        if(buy){
            profit=max(helper(idx+1,0,fee,prices,dp)-prices[idx]-fee,helper(idx+1,1,fee,prices,dp));
        }else{
            profit=max(helper(idx+1,1,fee,prices,dp)+prices[idx],helper(idx+1,0,fee,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        return helper(0,1,fee,prices,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends