//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end)
            return 0;
        
        int mod =1e5;
        vector<int> vis(mod,0);
        queue<pair<int,int> > q;
        q.push({start,0});
        vis[start]=1;
        while(!q.empty())
        {
            int m=q.front().first,n=q.front().second;
            q.pop();
            for(auto &val:arr)
            {
                int mul=(m%mod * val%mod)%mod;
                if(mul==end)
                    return n+1;
                if(vis[mul]==0)
                {
                     q.push({mul,n+1});
                     vis[mul]=1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends