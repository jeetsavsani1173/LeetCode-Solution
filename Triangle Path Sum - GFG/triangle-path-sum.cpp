//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp=triangle;
        
        for(int i=1;i<triangle.size();i++)
        {
            dp[i][0]+=dp[i-1][0];
            for(int j=1;j<triangle[i].size()-1;j++)
            {
                dp[i][j]+=min(dp[i-1][j],dp[i-1][j-1]);
            }
            dp[i][triangle[i].size()-1]+=dp[i-1][triangle[i].size()-2];
        }
        int ans=INT_MAX;
        for(int j=0;j<dp[n-1].size();j++)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends