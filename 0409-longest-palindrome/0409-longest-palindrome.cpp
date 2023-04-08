class Solution {
public:
    int longestPalindrome(string s) {
        int odd=0;
        int ans=0;
        unordered_map<int,int> mp;
        for(auto it:s) mp[it]++;
        
        for(auto it:mp)
        {
            if(it.second%2==1) odd++;
            ans+=((it.second/2)*2);
        }
        if(odd) ans++;
        return ans;
    }
};