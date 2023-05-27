//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int M;
    int recursion(int i,int j,vector<vector<int>> &obstacleGrid,int n,int m,vector<vector<int>> &dp)
    {
        if(i<0 || i>=n || j<0 || j>=m || obstacleGrid[i][j]==1)
            return 0;
        else if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=(recursion(i+1,j,obstacleGrid,n,m,dp)%M+recursion(i,j+1,obstacleGrid,n,m,dp)%M)%M;
        
        return dp[i][j]=ans;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        M=1e9+7;
        vector<vector<int>> dp(105,vector<int>(105,-1));
        return recursion(0,0,grid,n,m,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends