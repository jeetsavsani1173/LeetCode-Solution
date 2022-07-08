// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
string ans;
void printParenthesis(int i, int j, int n, int* bracket,
                      char& name)
{
    if (i == j) {
        ans.push_back(name++);
        return;
    }
 
    ans.push_back('(');
 
    printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name);
 
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name);
                     
    ans.push_back(')');
}
    string matrixChainOrder(int p[], int n){
        int m[n][n];
 
        int bracket[n][n];
     
        for (int i = 1; i < n; i++)
            m[i][i] = 0;
     
        for (int L = 2; L < n; L++)
        {
            for (int i = 1; i < n - L + 1; i++)
            {
                int j = i + L - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    int q = m[i][k] + m[k + 1][j]
                            + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
     
        char name = 'A';
        printParenthesis(1, n - 1, n, (int*)bracket, name);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends