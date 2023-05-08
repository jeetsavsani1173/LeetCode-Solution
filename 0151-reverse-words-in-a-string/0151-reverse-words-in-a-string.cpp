class Solution {
public:
    string reverseWords(string s) {
        vector<string> vect;
        string temp;
        int idx=0;
        while(idx<s.size())
        {
            while(idx<s.size() && s[idx]==' ')
                idx++;
            
            while(idx<s.size() && s[idx]!=' '){
                temp.push_back(s[idx]);
                idx++;
            }
            if(temp.size()>0) vect.push_back(temp);
            temp="";
        }
        reverse(vect.begin(),vect.end());
        string ans;
        for(int i=0;i<vect.size()-1;i++)
        {
            ans+=vect[i];
            ans.push_back(' ');
        }
        ans+=vect[vect.size()-1];
        return ans;
    }
};