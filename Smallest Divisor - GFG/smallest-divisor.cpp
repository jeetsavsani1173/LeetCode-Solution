//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int cost_function(vector<int> &nums,int k)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans+=ceil(1.0*nums[i]/k);
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high)
        {
            int midDivisor=low+(high-low)/2;
            if(cost_function(nums,midDivisor)<=threshold)
            {
                ans=midDivisor;
                high=midDivisor-1;
            }
            else
                low=midDivisor+1;
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
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends