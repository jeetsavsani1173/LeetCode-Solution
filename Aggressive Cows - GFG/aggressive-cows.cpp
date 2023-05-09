//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int check(vector<int> &stalls,int gap)
    {
        int cows=1;
        int prev=0;
        
        for(int i=1;i<stalls.size();i++){
            if((stalls[i]-stalls[prev])>=gap){
                prev=i;
                cows++;
            }
        }
        return cows;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int l=0,r=*max_element(stalls.begin(),stalls.end());
        
        int ans=-1;
        
        while(l<=r){
            int mid=(r-l)/2+l;
            if(check(stalls,mid)>=k){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends