class Solution {
public:
    vector<string> saperate(string s)
    {
        vector<string> ans;
        string temp;
        for(auto it:s){
            if(it!=' '){
                temp.push_back(it);
            }else{
                ans.push_back(temp);
                temp="";
            }
        }
        ans.push_back(temp);
        return ans;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> v=saperate(s);
        if(pattern.size()!=v.size()) return false;
        map<char,string> mp1;
        map<string,char> mp2;
        int i=0;
        for(auto it:pattern){
            if(mp1.find(it)!=mp1.end()){
                if(mp1[it]!=v[i]) return false;
            }else if(mp2.find(v[i])!=mp2.end()){
                if(mp2[v[i]]!=it) return false;
            }else{
                mp1[it]=v[i];
                mp2[v[i]]=it;
            }
            i++;
        }
        return true;
    }
};