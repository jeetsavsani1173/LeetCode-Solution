class Solution {
public:
    string removeStars(string s) {
        vector<bool> flags(s.size(),true);
        int count=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='*'){
                count++;
                flags[i]=false;
            }else if(count>0){
                count--;
                flags[i]=false;
            }
        }
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(flags[i]){
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};