//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second==b.second)
            return (a.first<b.first);
        return (a.second<b.second);
    }
    int minRemoval(int N, vector<vector<int>> &intervals) {
        int n=intervals.size();
        vector<pair<int,int>> vpr;
        for(int i=0;i<n;i++)
            vpr.push_back({intervals[i][0],intervals[i][1]});
        
        sort(vpr.begin(),vpr.end(),comp);
        
        int limit=INT_MIN;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(limit<=vpr[i].first)
            {
                cnt++;
                limit=vpr[i].second;
            }
        }
        return n-cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends