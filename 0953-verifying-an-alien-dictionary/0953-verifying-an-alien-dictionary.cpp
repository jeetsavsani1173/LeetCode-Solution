class Solution {
public:
    map<char,int> mp;
    bool fun(string &a,string &b)
    {
        for(int i=0;i<min(a.size(),b.size());i++)
        {
            if(mp[a[i]]==mp[b[i]])
                continue;
            else if(mp[a[i]]<mp[b[i]])
                return true;
            else
                return false;
        }
        if(a.size()<=b.size()) return true;
        else return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++)
            mp[order[i]]=i;
        
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(fun(words[i],words[j])==false){
                     return false;
                }
            }
        }
        
        return true;
    }
};