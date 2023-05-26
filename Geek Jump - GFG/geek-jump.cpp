//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int idx,int n,vector<int> &h,vector<int> &dp){
        if(idx==n-1) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int ans=INT_MAX;
        // Take one jump
        if(idx+1<n) ans=min(ans,abs(h[idx]-h[idx+1])+helper(idx+1,n,h,dp));

        // Tale two jump
        if(idx+2<n) ans=min(ans,abs(h[idx]-h[idx+2])+helper(idx+2,n,h,dp));
        
        return dp[idx]=ans;
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1,-1);
        return helper(0,n,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends