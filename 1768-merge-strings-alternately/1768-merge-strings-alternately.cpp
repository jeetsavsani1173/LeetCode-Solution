class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0,j=0;
        bool flag=true;
        string ans;
        while(i<n && j<m){
            if(flag){
                ans.push_back(word1[i++]);
            }else{
                ans.push_back(word2[j++]);
            }
            flag=!flag;
        }
        
        while(i<n) ans.push_back(word1[i++]);
        while(j<m) ans.push_back(word2[j++]);
        
        return ans;
    }
};