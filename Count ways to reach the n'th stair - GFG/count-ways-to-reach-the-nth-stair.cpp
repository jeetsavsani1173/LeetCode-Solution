//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int M=1e9+7;
    //Function to count number of ways to reach the nth stair.
    int helper(int i,int n,vector<int> &dp){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=(helper(i+1,n,dp)%M+helper(i+2,n,dp)%M)%M;
    }
    int countWays(int n)
    {
        M=1e9+7;
        vector<int> dp(n+1,-1);
        return helper(0,n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends