class Solution {
public:
    bool check(int idx,string &s,string &key)
    {
        for(int i=0;i<key.size();i++){
            if(key[i]!=s[i+idx]) return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size(),k=needle.size();
        if(n<k) return -1;
        if(haystack==needle) return 0;
        int i=0;
        while((i+k)<=n){
            if(check(i,haystack,needle)) return i;
            i++;
        }
        return -1;
    }
};