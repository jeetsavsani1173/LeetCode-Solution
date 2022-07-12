// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int MAX=5000;
  public:
    int shortestUnSub(string S, string T) {
        int m = S.size(), n = T.size();
 
        // declaring 2D array of m + 1 rows and
        // n + 1 columns dynamically
        int dp[m+1][n+1];
     
        // T string is empty
        for (int i = 0; i <= m; i++)
            dp[i][0] = 1;
     
        // S string is empty
        for (int i = 0; i <= n; i++)
            dp[0][i] = MAX;
     
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char ch = S[i-1];
                int k;
                for (k = j-1; k >= 0; k--)
                    if (T[k] == ch)
                        break;
     
                // char not present in T
                if (k == -1)
                    dp[i][j] = 1;
                else
                   dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
            }
        }
     
        int ans = dp[m][n];
        if (ans >= MAX)
            ans = -1;
     
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends