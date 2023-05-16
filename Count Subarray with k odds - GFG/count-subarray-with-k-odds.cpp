//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Exact k = AtMost(k) - AtMost(k-1) 
    int countOfSubarraysAtMostkOddNumber(vector<int> &nums,int k)
    {
        int left=0,count=0,ans=0;
        for(int right=0;right<nums.size();right++)
        {
            if(nums[right]&1) count++;
            
            while(count>k){
                if(nums[left]&1) count--;
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        int first=countOfSubarraysAtMostkOddNumber(nums,k);
        int second=countOfSubarraysAtMostkOddNumber(nums,k-1);
        return first-second;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends