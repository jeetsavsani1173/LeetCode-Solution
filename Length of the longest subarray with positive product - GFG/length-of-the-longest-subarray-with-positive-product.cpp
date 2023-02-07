//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &nums,int n){
           int ans=0;
            int s=-1,e=-1;
            int start_idx=0;
            int cnt=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0){
                    if(cnt%2==0) ans=max(ans,i-start_idx);
                    else{
                        if(e==-1){
                            ans=max(ans,max(i-s-1,s-start_idx));
                        }else{
                            ans=max(ans,(i-start_idx)-min(i-e,s-start_idx+1));
                        }
                    }
                    s=-1;
                    e=-1;
                    start_idx=i+1;
                    cnt=0;
                }else if(nums[i]<0){
                    cnt++;
                    if(s!=-1) e=i;
                    else s=i;
                }
            }
            if(cnt%2==0) ans=max(ans,n-start_idx);
            else{
                if(e==-1){
                    ans=max(ans,max(n-s-1,s-start_idx));
                }else{
                    ans=max(ans,(n-start_idx)-min(n-e,s-start_idx+1));
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends