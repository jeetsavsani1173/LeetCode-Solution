//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> seive(int n)
    {
        vector<int> is_prime(n + 1, -1);
        is_prime[0]=0;
        is_prime[1]=1;

        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]==-1) {
                for (int j = i * i; j <= n; j += i)
                {
                    if(is_prime[j]==-1)
                        is_prime[j] = i;
                }
            }
        }
        return is_prime;
    }
    vector<int> leastPrimeFactor(int n) {
        vector<int> prime=seive(n+1);
        for(int i=1;i<=n;i++){
            if(prime[i]==-1) prime[i]=i;
        }
        return prime;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends