class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int ans=mp[s[0]];
        for(int i=1;i<s.size();i++)
        {
            int curr=mp[s[i]];
            int prev=mp[s[i-1]];
            if(curr>prev)
            {
                ans-=prev;
                ans+=(curr-prev);
            }
            else
                ans+=curr;
        }
        return ans;
    }
};