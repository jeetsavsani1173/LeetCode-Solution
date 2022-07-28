class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> mp1,mp2;
        for(auto it:s) mp1[it]++;
        for(auto it:t) mp2[it]++;
        
        for(auto it:mp1){
            if(mp2[it.first]!=it.second) return false;
        }
        return true;
    }
};