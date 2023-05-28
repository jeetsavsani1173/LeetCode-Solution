//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    if(n==1) return nums[0];
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        
        int target=sum;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        for(int i=0;i<n;i++) dp[i][0]=1;
        dp[0][nums[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                // Non-Take
                dp[i][j]=dp[i][j] || dp[i-1][j];
                
                // Take
                if(j-nums[i]>=0) dp[i][j]=dp[i][j] || dp[i-1][j-nums[i]];
            }
        }
        
        int ans=INT_MAX;
        for(int j=target;j>=0;j--){
            if(dp[n-1][j]){
                ans=min(ans,abs(sum-2*j));
            }
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends