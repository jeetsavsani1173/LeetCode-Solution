//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> to_bin(int x){
            vector<int> ans;
            while(x){
                ans.push_back(x%2);
                x/=2;
            }
            return ans;
        }
        int to_Int(vector<int> &temp){
            int ans=0;
            for(int i=0;i<temp.size();i++){
                if(temp[i]){
                    ans+=(1<<i);
                }
            }
            return ans;
        }
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>> hash(N+1,vector<int>(32,0));
            for(auto it:U){
                int l=it[0];
                int r=it[1];
                int x=it[2];
                
                vector<int> bin=to_bin(x);
                
                for(int i=0;i<bin.size();i++){
                    if(bin[i]&1){
                        hash[l][i]+=1;
                        
                        if(r!=N){
                            hash[r+1][i]-=1;
                        }
                    }
                }
            }
            
            // Take prefix
            for(int i=1;i<=N;i++){
                for(int j=0;j<32;j++){
                    hash[i][j]+=hash[i-1][j];
                }
            }
            vector<int> ans;
            for(int i=1;i<=N;i++){
                ans.push_back(to_Int(hash[i]));
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends