//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int idx,int n,int cap,int val[],int wt[],vector<vector<int>> &dp)
    {
        if(idx==n) return 0;
        
        if(dp[idx][cap]!=-1) return dp[idx][cap];
        // Take
        int take=0;
        if(cap>=wt[idx])
            take=val[idx]+helper(idx,n,cap-wt[idx],val,wt,dp);
            
        int non_take=helper(idx+1,n,cap,val,wt,dp);
        
        return dp[idx][cap]=max(take,non_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        return helper(0,N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends