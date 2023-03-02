//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        int n=5,m=6;
        vector<int> vect(31);
        
        for(int i=0;i<31;i++)
            vect[i]=i;
            
        for(int i=0;i<2*N;i+=2){
            vect[arr[i]]=arr[i+1];
        }
        
        // Generate a Graph from grid
        vector<int> graph[n*m+1];
        for(int cell=1;cell<=n*m;cell++)
        {
            for(int move=1;move<=6 && cell+move<=(n*m);move++){
                if(cell==vect[cell+move]) continue;
                graph[cell].push_back(vect[cell+move]);
            }
        }
        // Apply BFS 
        vector<int> vis(n*m+1,-1);
        queue<pair<int,int>> q;
        q.push({1,0});
        
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(vis[node]!=-1) continue;
            vis[node]=dis;
            for(auto it:graph[node]){
                if(vis[it]==-1){
                    q.push({it,dis+1});
                }
            }
        }
        return vis[n*m];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends