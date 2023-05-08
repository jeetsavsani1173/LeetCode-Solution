//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int min(int a,int b)
    {
        return (a>b)?b:a;
    }
    string longestCommonPrefix (string strs[], int n)
    {
        string ans="";
        int mn_size=INT_MAX;
        for(int i=0;i<n;i++)
            mn_size=min(mn_size,strs[i].size());
        for(int j=0;j<mn_size;j++)
        {
            bool flag=true;
            char c=strs[0][j];
            for(int i=0;i<n;i++)
            {
                if(strs[i][j]!=c)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) ans+=c;
            else break;
        }
        
        return ans==""?"-1":ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends