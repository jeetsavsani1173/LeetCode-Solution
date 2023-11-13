class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch=='A' || ch =='E' || ch =='I' || ch == 'O' || ch == 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        string str = "";
        for(auto ch : s){
            if(isVowel(ch) == true) str += ch;
        }
        sort(str.begin(),str.end());
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i])){
                s[i] = str[idx];
                idx++;
            }
        }
        return s;
    }
};