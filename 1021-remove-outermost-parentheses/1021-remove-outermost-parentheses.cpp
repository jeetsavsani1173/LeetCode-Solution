class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans;
        for(auto &it:s)
        {
            if(it=='('){
                if(count) ans.push_back(it);
                count++;
            }else{
                count--;
                if(count) ans.push_back(it);
            }
        }
        return ans;
    }
};