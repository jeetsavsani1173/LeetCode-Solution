class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        
        for(char first='a';first<='z';first++)
        {
            for(char second='a';second<='z';second++)
            {
                if(first==second)
                    continue;
                if(mp[first]==0 || mp[second]==0)
                    continue;
                int s1=0,s2=0;
                for(int i=0;i<s.size();i++)
                {
                    if(s[i]==first)
                        s1++;
                    else if(s[i]==second)
                        s2++;
                    
                    if((s1-s2)<0)
                    {
                        s1=0;
                        s2=0;
                    }
                    
                    if(s1&&s2)
                        ans=max(ans,s1-s2);
                }
            }
        }
        reverse(s.begin(),s.end());
        for(char first='a';first<='z';first++)
        {
            for(char second='a';second<='z';second++)
            {
                if(first==second)
                    continue;
                if(mp[first]==0 || mp[second]==0)
                    continue;
                int s1=0,s2=0;
                for(int i=0;i<s.size();i++)
                {
                    if(s[i]==first)
                        s1++;
                    else if(s[i]==second)
                        s2++;
                    
                    if((s1-s2)<0)
                    {
                        s1=0;
                        s2=0;
                    }
                    
                    if(s1&&s2)
                        ans=max(ans,s1-s2);
                }
            }
        }
        return ans;
    }
};