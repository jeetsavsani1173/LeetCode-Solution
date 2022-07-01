class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int it=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        return (it==letters.size())?letters[0]:letters[it];
    }
};