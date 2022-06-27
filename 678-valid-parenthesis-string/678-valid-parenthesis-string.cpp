class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(open.size()>0) open.pop();
                else if(star.size()>0) star.pop();
                else return false;
            }
        }
        
        // extra opening bracket..
        if(open.size()>star.size()) return false;
        
        // check for replace * to ")"
        while(!open.empty())
        {
            if(open.top()>star.top()) return false;
            open.pop();
            star.pop();
        }
        
        return true;
    }
};