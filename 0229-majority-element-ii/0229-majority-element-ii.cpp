class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        
        for(auto it:nums){
            if(cnt1==0 && ele2!=it){
                ele1=it;
                cnt1=1;
            }else if(cnt2==0 && ele1!=it){
                ele2=it;
                cnt2=1;
            }else if(ele1==it) cnt1++;
            else if(ele2==it) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0,cnt2=0;
        for(auto it:nums){
            if(it==ele1) cnt1++;
            if(it==ele2) cnt2++;
        }
        
        if(cnt1>=((int)(n/3)+1)) ans.push_back(ele1);
        if(cnt2>=((int)(n/3)+1)) ans.push_back(ele2);
        return ans;
    }
};