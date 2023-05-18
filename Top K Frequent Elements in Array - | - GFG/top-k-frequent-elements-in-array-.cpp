//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        vector<pair<int,int>> vpr;
        
        for(auto it:mp)
            vpr.push_back({it.second,it.first});
        
        sort(vpr.begin(),vpr.end());
        reverse(vpr.begin(),vpr.end());
        
        vector<int> ans;
        int i=0;
        while(k--){
            ans.push_back(vpr[i].second);
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends