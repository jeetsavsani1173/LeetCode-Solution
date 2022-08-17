class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool flag=true;
        for(auto it:nums)
        {
            if(it==0) return 0;
            else if(it<0) flag^=true;
        }
        return flag==true?1:-1;
    }
};