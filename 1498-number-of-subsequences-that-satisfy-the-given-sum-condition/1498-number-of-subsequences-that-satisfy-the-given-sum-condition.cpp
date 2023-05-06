class Solution {
public:
    int M=1e9+7;
    long modPow(long n, long x)
    {
        if (x == 0) return 1ll;

        long pow = modPow(n, x / 2ll);

        if (x % 2 == 0)
            return ((pow % M) * (pow % M)) % M;
        else
            return ((((n % M) * (pow % M)) % M) * pow % M) % M;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        
        int i=0,j=n-1;
        while(i<=j){
            if((nums[i]+nums[j])<=target){
                ans=(ans%M+(modPow(2,j-i))%M)%M;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};