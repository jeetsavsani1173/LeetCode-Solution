class Solution {
public:
    bool isValid(string &s,string &t,int j){
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[j]) return false;
            j=(j+1)%t.size();
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<goal.size();i++){
            if(s[0]==goal[i]){
                if(isValid(s,goal,i)) return true;
            }
        }
        return false;
    }
};