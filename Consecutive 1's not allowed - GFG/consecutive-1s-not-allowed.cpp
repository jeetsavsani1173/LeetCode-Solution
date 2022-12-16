//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int  M=1e9+7;
	ll countStrings(int n) {
	    vector<vector<ll>> dp(2,vector<ll>(n,1ll));
	    
	    for(int j=1;j<n;j++)
	    {
	        dp[0][j]=(dp[0][j-1]+dp[1][j-1])%M;
	        dp[1][j]=dp[0][j-1]%M;
	    }
	    
	    return (dp[0][n-1]+dp[1][n-1])%M;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends