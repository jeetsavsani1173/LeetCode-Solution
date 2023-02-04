//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int helper(int idx,vector<long long int> &coins,long long int amount,vector<vector<long long int>> &dp)
    {
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(idx==coins.size()) return 0;

        if(dp[idx][amount]!=-1) return dp[idx][amount];
        // Take
        long long int Take=helper(idx,coins,amount-coins[idx],dp);

        // Non-Take
        long long int NonTake=helper(idx+1,coins,amount,dp);

        return dp[idx][amount]=(Take+NonTake);
    }
    long long int count(int coins[], int N, int sum) {
        vector<long long int> nums;
        for(int i=0;i<N;i++) nums.push_back(coins[i]);
        vector<vector<long long int>> dp(nums.size()+1,vector<long long int>(sum+1,-1));
        long long int ans=helper(0,nums,sum,dp);
        return ans==INT_MAX-1?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends