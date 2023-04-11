//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  class Disjoint{
        public:
        vector<int> par,size;
        Disjoint(int n){
            par.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) par[i]=i;
        }
        
        int findUPar(int n){
            if(par[n]==n) return n;
            return par[n]=findUPar(par[n]);
        }
        
        void UnionBySize(int u,int v)
        {
            int pu=findUPar(u);
            int pv=findUPar(v);
            
            if(par[pu]==par[pv]) return;
            if(size[pu]<size[pv]){
                par[pu]=pv;
                size[pv]+=size[pu];
            }else{
                par[pv]=pu;
                size[pu]+=size[pv];
            }
        }
    };
    bool isValid(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        Disjoint ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        vector<int> ans;
        
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int cell=row*m+col;
            
            int dx[4]={-1,0,+1,0};
            int dy[4]={0,+1,0,-1};
            
            for(int k=0;k<4;k++){
                int newX=row+dx[k];
                int newY=col+dy[k];
                
                if(isValid(newX,newY,n,m) && vis[newX][newY]){
                    int tempCell=newX*m+newY;
                    if(ds.findUPar(cell)!=ds.findUPar(tempCell)){
                        cnt--;
                        ds.UnionBySize(cell,tempCell);
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};



















//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends