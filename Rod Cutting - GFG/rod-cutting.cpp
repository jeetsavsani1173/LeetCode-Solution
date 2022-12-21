//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int idx,int n,int len,int price[],vector<vector<int>> &dp)
    {
        if(idx==len || n==0) return 0;
        
        if(dp[idx][n]!=-1) return dp[idx][n];
        // Take
        int take=0;
        if(n>=(idx+1))
            take=price[idx]+helper(idx,n-(idx+1),len,price,dp);
        
        // Non -Take
        int non_take=helper(idx+1,n,len,price,dp);
        
        return dp[idx][n]=max(take,non_take);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(0,n,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends