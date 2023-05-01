class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int cnt=0;
        for(auto it:nums){
            if(cnt==0) candidate=it;
            if(candidate==it) cnt++;
            else cnt--;
        }
        return candidate;
    }
};