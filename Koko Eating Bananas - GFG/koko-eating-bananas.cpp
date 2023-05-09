//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long check(vector<int> &piles,int k){
        long total_hours=0;
        for(auto it:piles){
            if(it%k==0){
                total_hours+=(1ll*it/k);
            }else{
                total_hours+=(1ll*it/k+1);
            }
        }
        return total_hours;
    }
    int Solve(int N, vector<int>& piles, int h) {
        long  l=1,r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r){
            long mid=(r-l)/2+l;
            if(check(piles,mid)<=h){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends