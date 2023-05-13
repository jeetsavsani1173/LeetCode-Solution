class Solution {
public:
    string find_str(vector<string> &v)
    {
        string ans=v[0];
        for(int i=1;i<v.size();i++){
            ans.push_back(' ');
            ans+=v[i];
        }
        return ans;
    }
    void helper(int idx,string &s,map<string,int> &mp,vector<string> &curr,vector<string> &ans)
    {
        if(idx==s.size()){
            ans.push_back(find_str(curr));
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(mp[s.substr(idx,i-idx+1)]!=0){
                curr.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,mp,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        map<string,int> mp;
        for(auto it:wordDict) mp[it]++;
        vector<string> curr;
        helper(0,s,mp,curr,ans);
        return ans;
    }
};