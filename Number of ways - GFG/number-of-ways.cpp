// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int helper(int N,vector<long long int> &dp)
    {
        if(N<0) return 0;
        if(N==0) return 1;
        if(dp[N]!=-1) return dp[N];
        return dp[N]=helper(N-1,dp)+helper(N-4,dp);
    }
    long long int arrangeTiles(int N){
        vector<long long int> dp(81,-1);
        return helper(N,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends