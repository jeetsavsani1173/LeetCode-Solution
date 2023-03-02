//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    pair<int,int> find_min(vector<int> &nums)
    {
        int mn=nums[0];
        int second_mn=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=mn){
                second_mn=mn;
                mn=nums[i];
            }else if(nums[i]>mn && nums[i]<=second_mn){
                second_mn=nums[i];
            }
        }
        return {mn,second_mn};
    }
    int minCost(vector<vector<int>> &costs) {
        int n=costs.size(),k=costs[0].size();
        if(n==k && n==1) return costs[0][0];
        if(k==1) return -1;
        vector<vector<int>> dp(n,vector<int>(k,0));
        dp=costs;
        
        for(int i=1;i<n;i++)
        {
            pair<int,int> pr=find_min(dp[i-1]);
            
            for(int j=0;j<k;j++)
            {
                if(pr.first==dp[i-1][j]){
                    dp[i][j]+=pr.second;
                }else{
                    dp[i][j]+=pr.first;
                }
            }
        }
        
        int ans=INT_MAX;
        for(int j=0;j<k;j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends