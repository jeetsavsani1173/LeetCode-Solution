class Solution {
public:
    string minWindow(string s, string t) {
        if(s=="" || t=="" || s.size()<t.size()) return "";
        
        map<char,int> req;
        for(int i=0;i<t.size();i++) req[t[i]]++;
        int temp=req.size();
        int matchCnt=0;
        int left=0,len=INT_MAX,start_idx=0;
        map<char,int> curr_mp;
        for(int right=0;right<s.size();right++)
        {
            char ch=s[right];
            curr_mp[ch]++;
            if(curr_mp[ch]==req[ch]) matchCnt++;
            if(req[ch]==0) req.erase(ch);
       
            while(matchCnt >= temp)
            {
                if(right-left < len)
                {
                    start_idx=left;
                    len=right-left+1;
                }
                char chl=s[left];
                if(curr_mp[chl]==req[chl]) matchCnt--;
                if(curr_mp[chl]==1) curr_mp.erase(chl);
                else curr_mp[chl]--;
                left++;
            }
        }
        if(len==INT_MAX) return "";
        string ans;
        for(int i=0;i<len;i++)
            ans+=s[start_idx+i];
        return ans;
    }
};