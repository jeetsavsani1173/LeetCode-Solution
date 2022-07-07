// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	bool isprime(int n)
    {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
    
        for (int i = 6L; i*i <= n; i += 6) {
            if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
        }
        return true;
    }
	int prime_factorization(int n)
    {
        int ans=0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                {
                    n /= i;
                    ans++;
                }
            }
        }
        if (n != 1)
            ans++;
        return ans;
    }
    bool brainGame(vector<int>nums) {
        vector<int> v(1005,0);
        for(int i=2;i<=1000;i++){
            if(!isprime(i)) v[i]=prime_factorization(i)-1;
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans=ans^v[nums[i]];
        
        return (ans!=0);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends