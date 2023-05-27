//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp=points;
        for(int i=1;i<n;i++){
            dp[i][0]+=max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]+=max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]+=max(dp[i-1][0],dp[i-1][1]);
        }
        
        int ans=0;
        ans=max(ans,max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));
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
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends