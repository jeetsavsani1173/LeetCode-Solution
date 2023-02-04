//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    if(n==1) return arr[0];
	    vector<int> dp(n,0);
	    dp[0]=arr[0];
	    dp[1]=arr[1];
	    int mx=dp[0];
	    int idx=0;
	    
	    for(int i=2;i<n;i++)
	    {
	        mx=max(mx,dp[idx]);
	        dp[i]=arr[i]+mx;
	        idx++;
	    }
	    int ans=0;
	    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends