class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> temp;
        for(auto it:nums) temp.push_back(it);
        for(auto it:nums) temp.push_back(it);
        
        stack<int> stk;
        vector<int> Tans;
        
        for(int i=temp.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=temp[i]) stk.pop();
            
            if(stk.size()==0) Tans.push_back(-1);
            else Tans.push_back(stk.top());
            
            stk.push(temp[i]);
        }
        reverse(Tans.begin(),Tans.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++) ans.push_back(Tans[i]);
        return ans;
    }
};