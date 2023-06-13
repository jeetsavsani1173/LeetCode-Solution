//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = { 0, 1, 0, -1};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src.first,src.second});
        
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int d=tp[0];
            int x=tp[1];
            int y=tp[2];
            
            if(x==dest.first && y==dest.second) return d;
            
            for(int k=0;k<4;k++){
                int newX=x+dx[k];
                int newY=y+dy[k];
                
                if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]==1){
                    grid[newX][newY]=0;
                    pq.push({d+1,newX,newY});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends