class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    string reverseVowels(string s) {
        vector<int> index;
        vector<char> vowels;
        
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i])){
                index.push_back(i);
                vowels.push_back(s[i]);
            }
        }
        
        reverse(vowels.begin(),vowels.end());
        for(int i=0;i<index.size();i++)
        {
            s[index[i]]=vowels[i];
        }
        
        return s;
    }
};