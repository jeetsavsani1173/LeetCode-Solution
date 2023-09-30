class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> stk;
        int mn=nums[0];
        
        for(int i=1;i<nums.size();i++){
            auto it=nums[i];
            while(!stk.empty() && stk.top().first<it){
                stk.pop();
                
            }
            if(!stk.empty()){
                if(it<stk.top().first && it>stk.top().second){
                    return true;
                }
            }
            stk.push({it,mn});
            mn=min(mn,it);
        }
        return false;
    }
};