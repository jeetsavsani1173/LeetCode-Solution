//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool helper(int idx,vector<int> &nums,int sum,vector<vector<int>> &dp)
    {
        if(sum==0) return 1;
        if(idx==nums.size()) return 0;
        if(sum<0) return false;
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        // Take
        if(helper(idx+1,nums,sum-nums[idx],dp)==true)
            return dp[idx][sum]=true;
        
        // Non_Take
        if(helper(idx+1,nums,sum,dp)==true) 
            return dp[idx][sum]=true;
            
        return dp[idx][sum]=false;
    }
    int equalPartition(int N, int arr[])
    {
        vector<int> nums;
        for(int i=0;i<N;i++) nums.push_back(arr[i]);
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum&1) return false;
        sum/=2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return helper(0,nums,sum,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends