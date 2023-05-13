//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow
        ,vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+row-col]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+row-col]=1;
                solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal, n);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+row-col]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<string>> answer;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; ++i)
            board[i] = s;

        vector<int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        solve(0, board, answer,leftRow,upperDiagonal,lowerDiagonal, n);
        vector<vector<int>> mat;
        for(auto ans:answer){
            vector<int> temp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ans[i][j]=='Q'){
                        // temp.push_back(i+1);
                        temp.push_back(j+1);
                    }
                }
            }
            mat.push_back(temp);
        }
        sort(mat.begin(),mat.end());
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends