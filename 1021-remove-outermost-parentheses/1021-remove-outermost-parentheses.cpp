class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans;
        for(auto &it:s)
        {
            if(it=='('){
                count++;
                if(count!=1) ans.push_back(it);
            }else{
                count--;
                if(count) ans.push_back(it);
            }
        }
        return ans;
    }
};