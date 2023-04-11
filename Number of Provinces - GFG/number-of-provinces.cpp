//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
    int numProvinces(vector<vector<int>> adj, int n) {
        Disjoint ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    ds.UnionBySize(i+1,j+1);
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==ds.par[i]) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends