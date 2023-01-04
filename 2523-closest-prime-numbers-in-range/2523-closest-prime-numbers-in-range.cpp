class Solution {
public:
    vector<bool> seives(int n)
    {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        return is_prime;
    }
    vector<int> closestPrimes(int left, int right) {
        if(left==right) return {-1,-1};
        vector<bool> seive=seives(right+1);
        vector<int> primes;
        for(int i=left;i<=right;i++)
            if(seive[i]){
                primes.push_back(i);
            }
        
        int mn=INT_MAX;
        
        for(int i=1;i<primes.size();i++)
        {
            mn=min(mn,primes[i]-primes[i-1]);
        }
        
        if(mn==INT_MAX) return {-1,-1};
        
        for(int i=0;i<primes.size()-1;i++)
        {
            if(primes[i+1]-primes[i]==mn){
                return {primes[i],primes[i+1]};
            }
        }
        return {};
    }
};