class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        vector<string> vect={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string temp;
        for(auto word:words)
        {
            for(auto it:word)
                temp+=vect[it-'a'];
            st.insert(temp);
            temp="";
        }
        
        return st.size();
    }
};