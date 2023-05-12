class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s)
        {
            if(it=='(' || it=='{' || it=='[')
                st.push(it);
            else
            {
                if(st.size()==0) return false;
                if(it==')') if(st.top()!='(') return false;
                if(it=='}') if(st.top()!='{') return false;
                if(it==']') if(st.top()!='[') return false;
                st.pop();
            }
        }
        return (st.size()==0);
    }
    void helper(int idx,string &s)
    {
        if(idx==s.size())
        {
            if(isValid(s)) ans.push_back(s);
            return;
        }
        // trying to put "("
        s[idx]='(';
        helper(idx+1,s);
        
        // // trying to put ")"
        s[idx]=')';
        helper(idx+1,s);
        
        // backTrack..
        s[idx]='0';
    }
    vector<string> generateParenthesis(int n) {
        string s;
        for(int i=0;i<2*n;i++)
            s+='0';
        
        helper(0,s);
        return ans;
    }
};