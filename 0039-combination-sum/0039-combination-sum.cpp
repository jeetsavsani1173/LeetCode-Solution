class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx,vector<int>& candidates,int target,vector<int> &temp)
    {
        if(idx==candidates.size()){
            if(target==0) ans.push_back(temp);
            return;
        }
        
        if(target>=candidates[idx]){
            // Take
            temp.push_back(candidates[idx]);
            helper(idx,candidates,target-candidates[idx],temp);
            temp.pop_back();
        }
        
        // NonTake
        helper(idx+1,candidates,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(0,candidates,target,temp);
        return ans;
    }
};