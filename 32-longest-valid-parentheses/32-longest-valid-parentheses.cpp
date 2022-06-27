class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') stk.push(i);
            else{
                if(stk.size()==0 || s[stk.top()]==')') stk.push(i);
                else if(s[stk.top()]=='('){
                    stk.pop();
                    int lastUnBalIdx=(stk.size()==0)?-1:stk.top();
                    ans=max(ans,i-lastUnBalIdx);
                }
            }
        }
        
        return ans;
    }
};