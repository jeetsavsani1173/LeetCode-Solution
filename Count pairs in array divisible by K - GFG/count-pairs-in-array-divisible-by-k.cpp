// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        long long ans=0;
        vector<long long> freq(K,0);
        for(int i=0;i<n;i++) freq[A[i]%K]++;
        
        ans+=(freq[0]*(freq[0]-1))/2;
        if(K&1){
            for(int i=1;i<=K/2;i++)
                ans+=freq[i]*freq[K-i];
        }else{
            for(int i=1;i<K/2;i++)
                ans+=freq[i]*freq[K-i];
            ans+=(freq[K / 2] * (freq[K / 2] - 1) / 2);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends