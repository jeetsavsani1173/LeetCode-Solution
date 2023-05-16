//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Exact (k) = atmost(k)- atmost(k-1)
    int atMost(vector<int> &nums,int k){
        int ans=0;
        int left=0;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            
            while(left<=right && sum>k){
                sum-=nums[left];
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int N, int goal){
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends