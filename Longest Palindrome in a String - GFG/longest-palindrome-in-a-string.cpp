//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int maxLen=0;
        int startIdx=0;
        for(int gape=0;gape<n;gape++){
            int i=0,j=gape;
            while(j<n){
                if(gape==0){
                    dp[i][j]=1;
                }else if(gape==1){
                    if(s[i]==s[j]){
                        dp[i][j]=2;
                    }else{
                        dp[i][j]=0;
                    }
                }else if(s[i]==s[j] && dp[i+1][j-1]>0){
                    dp[i][j]=2+dp[i+1][j-1];
                }
                if(dp[i][j]>maxLen){
                    maxLen=dp[i][j];
                    startIdx=i;
                }
                i++;
                j++;
            }
        }
        return s.substr(startIdx,maxLen);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends