//{ Driver Code Starts
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
    int Solve(int n, vector<vector<int>>& edge) {
        if(edge.size()+1<n) return -1;
        Disjoint ds(n);
        for(auto it:edge){
            ds.UnionBySize(it[0],it[1]);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==ds.par[i]) ans++;
        }
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends