//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int helper(int idx,int buy,int cap,int n,int prices[],vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(idx==n) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int profit=0;
        if(buy){
            profit=max(helper(idx+1,0,cap,n,prices,dp)-prices[idx]
                       ,helper(idx+1,1,cap,n,prices,dp));
        }else{
            profit=max(helper(idx+1,1,cap-1,n,prices,dp)+prices[idx]
                       ,helper(idx+1,0,cap,n,prices,dp));
        }
        return dp[idx][buy][cap]=profit;
    }
    int maxProfit(int k, int n, int A[]) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,n,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends