class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,number=0,ans=0;
        
        for(auto it:nums){
            if(cnt==0){
                ans=it;
            }
            if(ans==it) cnt++;
            else cnt--;
        }
        return ans;
    }
};