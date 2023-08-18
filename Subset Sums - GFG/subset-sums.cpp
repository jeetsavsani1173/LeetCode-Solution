//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void helper(int idx,vector<int> &nums,int sum,vector<int> &ans)
    {
        if(idx==nums.size()){
            ans.push_back(sum);
            return;
        }
        
        // Take
        helper(idx+1,nums,sum+nums[idx],ans);
        
        // Non-Tale
        helper(idx+1,nums,sum,ans);
    }
    vector<int> subsetSums(vector<int> &arr, int N)
    {
        vector<int> ans;
        int sum=0;
        helper(0,arr,sum,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends