// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    string temp="URDL";
    void rat_in_maze(int i,int j,int n,string curr,vector<vector<int>> &grid,vector<vector<bool>> &vis,vector<string>&ans)
    {
        if(i+1==n && j+1==n)
        {
            // cout<<curr<<endl;
            ans.push_back(curr);
            return;
        }
        
        for(int k=0;k<4;k++)
        {
            int newX=i+dx[k];
            int newY=j+dy[k];
            
            if(newX>=0 && newY>=0 && newX<n && newY<n && grid[newX][newY]==1 && !vis[newX][newY])
            {
                vis[newX][newY]=true;
                rat_in_maze(newX,newY,n,curr+temp[k],grid,vis,ans);
                vis[newX][newY]=false;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        string curr="";
        vis[0][0]=true;
        rat_in_maze(0,0,n,curr,m,vis,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends