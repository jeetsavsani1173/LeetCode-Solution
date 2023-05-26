//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(int idx,int n,int arr[],vector<int> &dp){
	    if(idx>=n) return 0;
	    if(dp[idx]!=-1) return dp[idx];
	    return dp[idx]=max(arr[idx]+helper(idx+2,n,arr,dp),helper(idx+1,n,arr,dp));
	}
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1,-1);
	    return helper(0,n,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends