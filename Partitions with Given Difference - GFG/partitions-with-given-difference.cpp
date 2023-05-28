//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int M=1e9+7;
	long helper(int idx,vector<int> &nums,int n,int sum,vector<vector<long>> &dp)
    {
        if(idx==n && sum==0) return 1;
        if(idx==n) return 0;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        // Take
        long count=0;
        if(sum>=nums[idx])
            count+=helper(idx+1,nums,n,sum-nums[idx],dp);
        
        // Non_Take
        count+=helper(idx+1,nums,n,sum,dp);
            
        return dp[idx][sum]=(count%M);
    }
    int countPartitions(int n, int d, vector<int>& nums) {
        M=1e9+7;
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum-d<0 || (sum-d)%2) return 0;
        vector<vector<long>> dp(n+1,vector<long>((sum-d)/2+1,-1));
        return helper(0,nums,n,(sum-d)/2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends