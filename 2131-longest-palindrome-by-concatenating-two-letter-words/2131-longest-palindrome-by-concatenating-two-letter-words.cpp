class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        map<string,int> mp;
        for(auto it:words) mp[it]++;
        int mx=0;
        bool flag=false;
        for(auto it:mp)
        {
            string rev=it.first;
            reverse(rev.begin(),rev.end());
            int freq1=it.second;
            int freq2=mp[rev];
            
            if(it.first==rev){
                if(freq1%2==1){
                    flag=true;
                }
                ans+=4*(freq1/2);
                continue;
            }
            
            ans+=4*(min(freq1,freq2));
            mp[it.first]=0;
            mp[rev]=0;
        }
        ans+=(flag)?(2):(0);
        return ans;
    }
};