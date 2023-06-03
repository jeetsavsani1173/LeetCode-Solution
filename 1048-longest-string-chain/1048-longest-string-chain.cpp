class Solution {
public:
    static bool comp(string &st1,string &st2)
    {
        return st1.size()<st2.size();
    }
    bool check(string &st1,string &st2)
    {
        if(st1.size()+1!=st2.size()) return false;
        int first=0,second=0;
        
        while(second<st2.size())
        {
            if(first<st1.size() && st1[first]==st2[second])
                first++,second++;
            else
                second++;
        }
        
        return (first==st1.size() && second==st2.size());
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int mx=0;
        vector<int> dp(words.size(),1);
        // LIS version of DP..
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[j],words[i]) && dp[j]+1>dp[i])
                    dp[i]=1+dp[j];
            }
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};