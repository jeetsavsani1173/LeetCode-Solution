class Solution {
public:
    int rev(int num){
        int ans=0;
        while(num){
            ans=ans*10+(num%10);
            num/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int M=1000000007;
        unordered_map<int,int> ump;
        int ans=0;
        for(auto it:nums){
            int temp=it-rev(it);
            
            ans=(ans+ump[temp])%M;
            ump[temp]++;
        }
        return ans%M;
    }
};