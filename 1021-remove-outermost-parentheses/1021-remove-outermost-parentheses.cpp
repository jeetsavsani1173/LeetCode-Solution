class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') stk.push(i);
            else{
                if(stk.size()==1){
                    s[stk.top()]='0';
                    s[i]='0';
                }
                stk.pop();
            }
        }
        
        string ans;
        for(auto &it:s)
            if(it!='0')
                ans.push_back(it);
        
        return ans;
    }
};