class Solution {
public:
    vector<bool> seive(int n)
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
    int downTo(int curr,int next,vector<bool> &prime){
        for(int i=2;i<=1005;i++){
            if(i>=curr) break;
            if(prime[i]){
                if((curr-i)<next){
                    return curr-i;
                }
            }
        }
        return curr;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> prime=seive(100005);
        // cout<<prime[997]<<endl;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                nums[i]=downTo(nums[i],nums[i+1],prime);
            }
            if(nums[i]>=nums[i+1]){
                // cout<<i<<" ";
                return false;
            }
        }
        // for(auto it:nums)
        //     cout<<it<<" ";
        // cout<<endl;
        return true;
    }
};