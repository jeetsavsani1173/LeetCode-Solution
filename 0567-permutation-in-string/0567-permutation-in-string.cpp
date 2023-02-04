class Solution {
public:
    bool check(vector<int> &mp1,vector<int> &mp2)
    {
        for(int i=0;i<26;i++)
            if(mp1[i]!=mp2[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int k=s1.size();
        vector<int> freq_mp1(26,0);
        vector<int> freq_mp2(26,0);
        for(auto it:s1) freq_mp1[it-'a']++;
        
        for(int i=0;i<k;i++)
            freq_mp2[s2[i]-'a']++;
        
        if(check(freq_mp1,freq_mp2))
            return true;
        for(int i=k;i<s2.size();i++)
        {
            freq_mp2[s2[i]-'a']++;
            freq_mp2[s2[i-k]-'a']--;
            
            if(check(freq_mp1,freq_mp2))
                return true;
        }
        return false;
    }
};