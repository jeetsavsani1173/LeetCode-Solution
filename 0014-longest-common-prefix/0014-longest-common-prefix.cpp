class Solution {
public:
    
    int min(int a,int b)
    {
        return (a>b)?b:a;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int mn_size=INT_MAX;
        for(int i=0;i<strs.size();i++)
            mn_size=min(mn_size,strs[i].size());
        for(int j=0;j<mn_size;j++)
        {
            bool flag=true;
            char c=strs[0][j];
            for(int i=0;i<strs.size();i++)
            {
                if(strs[i][j]!=c)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) ans+=c;
            else break;
        }
        
        return ans;
    }
};