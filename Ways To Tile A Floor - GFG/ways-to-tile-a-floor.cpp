//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long numberOfWays(long long N) {
        if(N==1) return 1ll;
            
        int M=1e9+7;
        vector<long long> dp(N+1);
        dp[0]=1,dp[1]=2;
        
        for(int i=2;i<N;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%M;
        }
        return dp[N-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends