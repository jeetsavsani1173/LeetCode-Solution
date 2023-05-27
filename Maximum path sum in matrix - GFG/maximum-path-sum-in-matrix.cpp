//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0){
                    matrix[i][j]+=max(matrix[i-1][j],matrix[i-1][j+1]);
                }else if(j==n-1){
                    matrix[i][j]+=max(matrix[i-1][j],matrix[i-1][j-1]);
                }else{
                    matrix[i][j]+=max(max(matrix[i-1][j],matrix[i-1][j+1]),matrix[i-1][j-1]);
                }
            }
        }
        
        int ans=INT_MIN;
        for(int j=0;j<n;j++)
            ans=max(ans,matrix[n-1][j]);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends