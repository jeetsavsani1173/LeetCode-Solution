class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        while(num){
            digits.push_back(num%10);
            num/=10;
        }
        reverse(digits.begin(),digits.end());
        for(int i=0;i<digits.size();i++)
            if(digits[i]==6){
                digits[i]=9;
                break;
            }
        
        int ans=0;
        for(int i=0;i<digits.size();i++)
            ans=ans*10+digits[i];
        return ans;
    }
};