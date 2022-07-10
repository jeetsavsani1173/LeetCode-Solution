// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;
    void helper(int i,int j,int n,int m,vector<int> &rsf,vector<vector<int>> &grid)
    {
        if(i==n-1 && j==m-1)
        {
            rsf.push_back(grid[i][j]);
            ans.push_back(rsf);
            rsf.pop_back();
            return;
        }
        
        // down move..
        if((i+1)>=0 && (j)>=0 && (i+1)<n && (j)<m){
            rsf.push_back(grid[i][j]);
            helper(i+1,j,n,m,rsf,grid);
            rsf.pop_back();
        }
        
        //right move..
        if(i>=0 && (j+1)>=0 && i<n && (j+1)<m){
            rsf.push_back(grid[i][j]);
            helper(i,j+1,n,m,rsf,grid);
            rsf.pop_back();
        }
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> rsf;
        helper(0,0,n,m,rsf,grid);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends