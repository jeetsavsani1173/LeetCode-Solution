//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &arr) {
        stack<int> st1,st2;
        vector<int> next_smaller(n),pre_smaller(n);
        for(int i=0;i<n;i++)
        {
            next_smaller[i]=n-i-1;
            pre_smaller[i]=i;
        }
        
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()]>arr[i])
            {
                next_smaller[st1.top()]=i-st1.top()-1;
                st1.pop();
            }
            st1.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && arr[st2.top()]>=arr[i])
            {
                pre_smaller[st2.top()]=st2.top()-i-1;
                st2.pop();
            }
            st2.push(i);
        }
        
        long long ans=0;
        long long M=1e9+7;
        
        for(int i=0;i<n;i++)
        {
            ans+=(arr[i]*1ll*(pre_smaller[i]+1)*(next_smaller[i]+1));
            ans%=M;
        }
        return (int)ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends