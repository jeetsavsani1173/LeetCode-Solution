class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans="";
        
        for(auto it:s)
        {
            if(it==' '){
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back(' ');
            }else{
                st.push(it);
            }
        }
        
        if(!st.empty())
        {
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
        }
        
        return ans;
    }
};