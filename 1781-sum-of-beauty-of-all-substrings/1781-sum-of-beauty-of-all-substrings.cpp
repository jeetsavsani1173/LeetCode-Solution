class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        
        for(int i=0;i<s.size();i++){
            vector<int> hash(26,0);
            int mn_freq=0,mx_freq=0;
            for(int j=i;j<s.size();j++){
                int idx=s[j]-'a';
                mx_freq=max(mx_freq,++hash[idx]);
                if (mn_freq >= hash[idx] - 1) {
                    mn_freq = hash[idx];
                    for (int k = 0; k < 26; ++k)
                        mn_freq = min(mn_freq, hash[k] == 0 ? INT_MAX : hash[k]);
                }
                ans+=mx_freq-mn_freq;
            }
        }
        
        
        return ans;
    }
};