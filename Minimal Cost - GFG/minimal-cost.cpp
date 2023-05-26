//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int idx,int n,int k,vector<int> &h,vector<int> &dp){
        if(idx==n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX;
        for(int jump=1;jump<=k;jump++){
            if(idx+jump<n) ans=min(ans,abs(h[idx]-h[idx+jump])+helper(idx+jump,n,k,h,dp));
        }
        return dp[idx]=ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1,-1);
        return helper(0,n,k,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends