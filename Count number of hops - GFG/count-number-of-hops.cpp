//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long solve(int i, int n,vector<int> &dp){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long inc1 = solve(i+1,n,dp)%1000000007;
        long long inc2 = solve(i+2,n,dp)%1000000007;
        long long inc3 = solve(i+3,n,dp)%1000000007;
        
        return dp[i]=(inc1+inc2+inc3)%1000000007;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<int> dp(n+1,-1);
        return solve(0,n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends