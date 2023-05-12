//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> ans;
    void find_subset_sum(int idx,vector<int> &nums,vector<int> &temp,int target,int k)
    {
        if(idx==nums.size())
        {
            if(target==0 && temp.size()==k)
                ans.push_back(temp);
            return;
        }
        // take
        if(nums[idx]<=target)
        {
            temp.push_back(nums[idx]);
            find_subset_sum(idx+1,nums,temp,target-nums[idx],k);
            temp.pop_back();
        }
        
        // non-take
        find_subset_sum(idx+1,nums,temp,target,k);
        
    }
    vector<vector<int>> combinationSum(int k, int n) {
        vector<int> num;
        for(int i=1;i<=9;i++) num.push_back(i);
        vector<int> temp;
        find_subset_sum(0,num,temp,n,k);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends