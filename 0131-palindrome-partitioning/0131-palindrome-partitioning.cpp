class Solution {
public:
    bool isPAL(string &s,int start,int end)
    {
        while(start<=end)
            if(s[start++]!=s[end--]) return false;
        return true;
    }
    void helper(int idx,string &s,vector<string> &currAns,vector<vector<string>> &ans)
    {
        if(idx==s.size()){
            ans.push_back(currAns);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPAL(s,idx,i)){
                currAns.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,currAns,ans);
                currAns.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.size()==0) return ans;
        
        vector<string> currAns;
        helper(0,s,currAns,ans);
        return ans;
    }
};