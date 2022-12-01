class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    bool halvesAreAlike(string s) {
        int count1=0,count2=0;
        for(int i=0;i<s.size()/2;i++)
            if(isVowel(s[i]))
                count1++;
        
        for(int i=s.size()/2;i<s.size();i++)
            if(isVowel(s[i]))
                count2++;
        
        return count1==count2;
    }
};