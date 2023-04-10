class Solution {
public:
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
};